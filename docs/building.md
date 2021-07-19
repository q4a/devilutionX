# Building from Source

Note: If you do not use git to manage the source you must provide the version to CMake manually:
```bash
cmake .. -DVERSION_NUM=1.0.0 -DVERSION_SUFFIX=FFFFFFF -DCMAKE_BUILD_TYPE=Release
```

<details><summary>Linux</summary>

### Installing dependencies on Debian and Ubuntu
```
sudo apt-get install cmake g++ libsdl2-mixer-dev libsdl2-ttf-dev libsodium-dev
```
### Installing dependencies on Fedora
```
sudo dnf install cmake glibc-devel SDL2-devel SDL2_ttf-devel SDL2_mixer-devel libsodium-devel libasan libubsan
```
### Compiling
```
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)
```
</details>

<details><summary>macOS</summary>

Make sure you have [Homebrew](https://brew.sh/) installed, then run:

```
brew bundle install
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . -j $(sysctl -n hw.physicalcpu)
```
</details>
<details><summary>FreeBSD</summary>

### Installing dependencies
```
pkg install cmake sdl2_mixer sdl2_ttf libsodium
```
### Compiling
```
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . -j $(sysctl -n hw.ncpu)
```
</details>
<details><summary>NetBSD</summary>

### Installing dependencies
```
pkgin install cmake SDL2_mixer SDL2_ttf libsodium
```
### Compiling
```
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . -j $(sysctl -n hw.ncpu)
```
</details>

<details><summary>OpenBSD</summary>

### Installing dependencies
```
pkg_add cmake sdl2-mixer sdl2-ttf libsodium gmake
```
### Compiling
```
cd build
cmake .. -DCMAKE_MAKE_PROGRAM=gmake -DCMAKE_BUILD_TYPE=Release
cmake --build . -j $(sysctl -n hw.ncpuonline)
```
</details>

<details><summary>Windows via MinGW</summary>

### Installing dependencies on WSL, Debian and Ubuntu

### 32-bit

Download and place the 32bit MinGW Development Libraries of [SDL2](https://www.libsdl.org/download-2.0.php), [SDL2_mixer](https://www.libsdl.org/projects/SDL_mixer/), [SDL2_ttf](https://www.libsdl.org/projects/SDL_ttf/) and [Libsodium](https://github.com/jedisct1/libsodium/releases) in `/usr/i686-w64-mingw32`. This can be done automatically by running `Packaging/windows/mingw-prep.sh`.

```
sudo apt-get install cmake gcc-mingw-w64-i686 g++-mingw-w64-i686 pkg-config-mingw-w64-i686
```

### 64-bit

Download and place the 64bit MinGW Development Libraries of [SDL2](https://www.libsdl.org/download-2.0.php), [SDL2_mixer](https://www.libsdl.org/projects/SDL_mixer/), [SDL2_ttf](https://www.libsdl.org/projects/SDL_ttf/) and [Libsodium](https://github.com/jedisct1/libsodium/releases) in `/usr/x86_64-w64-mingw32`. This can be done automatically by running `Packaging/windows/mingw-prep64.sh`.

```
sudo apt-get install cmake gcc-mingw-w64-x86-64 g++-mingw-w64-x86-64 pkg-config-mingw-w64-x86-64
```
### Compiling

### 32-bit

```
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=../CMake/mingwcc.cmake -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)
```

### 64-bit

```
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=../CMake/mingwcc64.cmake -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)
```

Note: If your `(i686|x86_64)-w64-mingw32` directory is not in `/usr` (e.g. when on Debian), the mingw-prep scripts and the CMake
command won't work. You need adjust the mingw-prep scripts and pass `-DCROSS_PREFIX=/path` to CMake to set the path to the parent
of the `(i686|x86_64)-w64-mingw32` directory.
</details>
<details><summary>Windows via Visual Studio</summary>

### Installing dependencies
Make sure to install the `C++ CMake tools for Windows` component for Visual Studio.

* **Using vcpkg (recommended)**
1. Install vcpkg following the instructions from https://github.com/microsoft/vcpkg#quick-start.

   Don't forget to perform _user-wide integration_ step for additional convenience.
2. Install required dependencies by executing the following command (via cmd or powershell):

   For the 64-bit version of the dependencies please run this command:

   ```
   vcpkg install fmt:x64-windows sdl2:x64-windows sdl2-mixer:x64-windows sdl2-ttf:x64-windows libsodium:x64-windows gtest:x64-windows
   ```

   For the 32-bit version of the dependencies please run this command:

   ```
   vcpkg install fmt:x86-windows sdl2:x86-windows sdl2-mixer:x86-windows sdl2-ttf:x86-windows libsodium:x86-windows gtest:x86-windows
   ```

* **Manually**
1. Download and place the MSVC Development Libraries of [SDL2](https://www.libsdl.org/download-2.0.php), [SDL2_mixer](https://www.libsdl.org/projects/SDL_mixer/), [SDL2_ttf](https://www.libsdl.org/projects/SDL_ttf/) and [Libsodium](https://github.com/jedisct1/libsodium/releases) in `%USERPROFILE%\AppData\Local\Microsoft\WindowsApps\`.
2. If dependencies are not found or you wish to place them in other location - configure required path variables in _"Manage Configurations..."_ dialog inside Visual Studio or in _cmake-gui_.

### Compiling

* **Through Open->CMake in Visual Studio**
1. Go to `File -> Open -> CMake`, select `CMakeLists.txt` from the project root.
2. Select `Build devilution.exe` from the `Build` menu.

* **Through cmake-gui**

1. Input the path to devilutionx source directory at `Where is the source code:` field.
2. Input the path where the binaries would be placed at `Where to build the binaries:` field. If you want to place them inside source directory it's preferable to do so inside directory called `build` to avoid the binaries being added to the source tree.
3. It's recommended to input `Win32` in `Optional Platform for Generator`, otherwise it will default to x64 build.
4. In case you're using `vcpkg` select `Specify toolchain file for cross-compiling` and select the file `scripts/buildsystems/vcpkg.cmake` from `vcpkg` directory otherwise just go with `Use default native compilers`.
5. In case you need to select any paths to dependencies manually do this right in cmake-gui window.
6. Press `Generate` and open produced `.sln` file using Visual Studio.
7. Use build/debug etc. commands inside Visual Studio Solution like with any normal Visual Studio project.
</details>

<details><summary>Nintendo Switch</summary>
Run:

```
Packaging/switch/build.sh
```

This will install the [Switch devkit](https://switchbrew.org/wiki/Setting_up_Development_Environment) and build a DevilutionX Switch package. If you already have the devkit installed, or are on a non-Debian system, pass the the devkit path to the script like this:

```
DEVKITPRO=<path to devkit> Packaging/switch/build.sh
```

The nro-file will be generated in the build folder. Test with an emulator (RyuJinx) or real hardware.

[Nintendo Switch manual](docs/manual/platforms/switch.md)
</details>

<details><summary>Android</summary>

### Installing dependencies
Install [Android Studio](https://developer.android.com/studio)
After first launch configuration, go to "Configure -> SDK Manager -> SDK Tools".
Select "NDK (Side by side)" and "CMake" checkboxes and click "OK".

### Compiling
Click "Open Existing Project" and choose "android-project" folder in DevilutionX root folder.
Wait until Gradle sync is completed.
In Android Studio, go to "Build -> Make Project" or use the shortcut Ctrl+F9
You can find the compiled APK in `/android-project/app/build/outputs/apk/`
</details>

<details><summary>Nintendo 3DS</summary>

### Installing dependencies

https://devkitpro.org/wiki/Getting_Started


- Install (dkp-)pacman: https://devkitpro.org/wiki/devkitPro_pacman

- Install required packages with (dkp-)pacman:
```
sudo (dkp-)pacman -S \
		devkitARM general-tools 3dstools devkitpro-pkgbuild-helpers \
		libctru citro3d 3ds-sdl 3ds-sdl_ttf 3ds-freetype 3ds-cmake \
		3ds-pkg-config picasso 3dslink
```
- Download or compile [bannertool](https://github.com/Steveice10/bannertool/releases) and [makerom](https://github.com/jakcron/Project_CTR/releases)
  - Copy binaries to: `/opt/devkitpro/tools/bin/`

### Compiling
_If you are compiling using MSYS2, you will need to run `export MSYS2_ARG_CONV_EXCL=-D` before compiling.
Otherwise, MSYS will sanitize file paths in compiler flags which will likely lead to errors in the build._

```
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=/opt/devkitpro/cmake/3DS.cmake -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)
```
The output files will be generated in the build folder.

[Nintendo 3DS manual](/docs/manual/platforms/n3ds.md)
</details>

<details><summary>PlayStation Vita</summary>

### Compiling
```
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=${VITASDK}/share/vita.toolchain.cmake -DCMAKE_BUILD_TYPE=Release
make
```
[PlayStation Vita manual](docs/manual/platforms/vita.md)
</details>


<details><summary>Haiku</summary>

### Installing dependencies on 32 bit Haiku
```
pkgman install cmake_x86 devel:libsdl2_x86 devel:libsdl2_mixer_x86 devel:libsdl2_ttf_x86 devel:libsodium_x86
```
### Installing dependencies on 64 bit Haiku
```
pkgman install cmake devel:libsdl2 devel:libsdl2_mixer devel:libsdl2_ttf devel:libsodium
```
### Compiling on 32 bit Haiku
```
cd build
setarch x86 #Switch to secondary compiler toolchain (GCC8+)
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . -j $(nproc)
```
### Compiling on 64 bit Haiku
No setarch required, as there is no secondary toolchain on x86_64, and the primary is GCC8+
```
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . -j $(nproc)
```
</details>

<details><summary>OpenDingux / RetroFW</summary>

DevilutionX uses buildroot to build packages for OpenDingux and RetroFW.

The build script does the following:

1. Downloads and configures the buildroot if necessary.
2. Builds the executable (using CMake).
3. Packages the executable and all related resources into an `.ipk` or `.opk` package.

The buildroot uses ~2.5 GiB of disk space and can take 20 minutes to build.

For OpenDingux builds `mksquashfs` needs to be installed.

To build, run the following command

~~~ bash
Packaging/OpenDingux/build.sh <platform>
~~~

Replace `<platform>` with one of: `retrofw`, `rg350`, or `gkd350h`.

This prepares and uses the buildroot at `$HOME/buildroot-$PLATFORM-devilutionx`.

End-user manuals are available here:

* [RetroFW manual](docs/manual/platforms/retrofw.md)
* [RG-350 manual](docs/manual/platforms/rg350.md)
* [GKD350h manual](docs/manual/platforms/gkd350h.md)

</details>

<details><summary>Clockwork PI GameShell</summary>

You can either call
~~~ bash
Packaging/cpi-gamesh/build.sh
~~~
to install dependencies and build the code.

Or you create a new directory under `/home/cpi/apps/Menu` and copy [the file](Packaging/cpi-gamesh/__init__.py) there. After restarting the UI, you can download and compile the game directly from the device itself. See [the readme](Packaging/cpi-gamesh/readme.md) for more details.
</details>

<details><summary>Amiga via Docker</summary>

### Build the container from the repo root

~~~ bash
docker build -f Packaging/amiga/Dockerfile -t devilutionx-amiga .
~~~

### Build DevilutionX Amiga binary

~~~ bash
docker run --rm -v "${PWD}:/work" devilutionx-amiga
sudo chown -R "${USER}:" build-amiga
~~~

The command above builds DevilutionX in release mode.
For other build options, you can run the container interactively:

~~~ bash
docker run -ti --rm -v "${PWD}:/work" devilutionx-amiga bash
~~~

See the `CMD` in `Packaging/amiga/Dockerfile` for reference.

### Copy the necessary files

Outside of the Docker container, from the DevilutionX directory, run:

~~~ bash
sudo chown -R "${USER}:" build-amiga
cp Packaging/amiga/devilutionx.info Packaging/amiga/LiberationSerif-Bold.ttf build-amiga/
~~~

To actually start DevilutionX, increase the stack size to 50KiB in Amiga.
You can do this by selecting the DevilutionX icon, then hold right mouse button and
select Icons -> Information in the top menu.
</details>

<details><summary><b>CMake build options</b></summary>

### General
- `-DCMAKE_BUILD_TYPE=Release` changed build type to release and optimize for distribution.
- `-DNONET=ON` disable network support, this also removes the need for the ASIO and Sodium.
- `-DUSE_SDL1=ON` build for SDL v1 instead of v2, not all features are supported under SDL v1, notably upscaling.
- `-DCMAKE_TOOLCHAIN_FILE=../CMake/32bit.cmake` generate 32bit builds on 64bit platforms (remember to use the `linux32` command if on Linux).

### Debug builds
- `-DDEBUG=OFF` disable debug mode of the Diablo engine.
- `-DASAN=OFF` disable address sanitizer.
- `-DUBSAN=OFF` disable undefined behavior sanitizer.

</details>
