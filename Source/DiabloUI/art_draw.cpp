#include "DiabloUI/art_draw.h"

#include "DiabloUI/diabloui.h"
#include "utils/display.h"
#include "utils/sdl_compat.h"

namespace devilution {

void DrawArt(Sint16 screenX, Sint16 screenY, Art *art, int nFrame, Uint16 srcW, Uint16 srcH)
{
	if (screenY >= gnScreenHeight || screenX >= gnScreenWidth || art->surface == nullptr)
		return;

	SDL_Rect srcRect;
	srcRect.x = 0;
	srcRect.y = nFrame * art->h();
	srcRect.w = art->w();
	srcRect.h = art->h();

	ScaleOutputRect(&srcRect);

	if (srcW != 0 && srcW < srcRect.w)
		srcRect.w = srcW;
	if (srcH != 0 && srcH < srcRect.h)
		srcRect.h = srcH;
	SDL_Rect dstRect = { screenX, screenY, srcRect.w, srcRect.h };
	ScaleOutputRect(&dstRect);

	if (art->surface->format->BitsPerPixel == 8 && art->palette_version != pal_surface_palette_version) {
		if (SDLC_SetSurfaceColors(art->surface.get(), pal_surface->format->palette) <= -1)
			ErrSdl();
		art->palette_version = pal_surface_palette_version;
	}

	if (SDL_BlitSurface(art->surface.get(), &srcRect, DiabloUiSurface(), &dstRect) < 0)
		ErrSdl();
}

void DrawArt(const Surface &out, Sint16 screenX, Sint16 screenY, Art *art, int nFrame, Uint16 srcW, Uint16 srcH)
{
	if (screenY >= gnScreenHeight || screenX >= gnScreenWidth || art->surface == nullptr)
		return;

	SDL_Rect srcRect;
	srcRect.x = 0;
	srcRect.y = nFrame * art->h();
	srcRect.w = art->w();
	srcRect.h = art->h();

	if (srcW != 0 && srcW < srcRect.w)
		srcRect.w = srcW;
	if (srcH != 0 && srcH < srcRect.h)
		srcRect.h = srcH;
	SDL_Rect dstRect;
	dstRect.x = screenX;
	dstRect.y = screenY;
	dstRect.w = srcRect.w;
	dstRect.h = srcRect.h;

	if (art->surface->format->BitsPerPixel == 8 && art->palette_version != pal_surface_palette_version) {
		if (SDLC_SetSurfaceColors(art->surface.get(), out.surface->format->palette) <= -1)
			ErrSdl();
		art->palette_version = pal_surface_palette_version;
	}

	if (SDL_BlitSurface(art->surface.get(), &srcRect, out.surface, &dstRect) < 0)
		ErrSdl();
}

void DrawAnimatedArt(Art *art, int screenX, int screenY)
{
	DrawArt(screenX, screenY, art, GetAnimationFrame(art->frames));
}

int GetAnimationFrame(int frames, int fps)
{
	int frame = (SDL_GetTicks() / fps) % frames;

	return frame > frames ? 0 : frame;
}

} // namespace devilution
