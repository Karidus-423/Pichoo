{ stdenv
, lib
, fetchFromGitHub
, cmake
, fetchpatch
, libGLU
, glfw
, libX11
, libXi
, libXcursor
, libXrandr
, libXinerama
, alsaSupport ? stdenv.hostPlatform.isLinux
, alsa-lib
, pulseSupport ? stdenv.hostPlatform.isLinux
, libpulseaudio
, sharedLib ? true
, includeEverything ? true
, raylib-games
, darwin
, autoPatchelfHook
}:
let
  inherit (darwin.apple_sdk.frameworks) Carbon Cocoa OpenGL;
in
stdenv.mkDerivation (finalAttrs: {
  pname = "raylib";
  version = "5.5";

  src = fetchFromGitHub {
    owner = "raysan5";
    repo = "raylib";
    rev = finalAttrs.version;
    hash = "sha256-J99i4z4JF7d6mJNuJIB0rHNDhXJ5AEkG0eBvvuBLHrY=";
  };

  nativeBuildInputs = [
    cmake
  ] ++ lib.optional stdenv.hostPlatform.isLinux autoPatchelfHook;

  buildInputs = [ glfw ]
    ++ lib.optionals stdenv.hostPlatform.isLinux [ libXi libXcursor libXrandr libXinerama ]
    ++ lib.optionals stdenv.hostPlatform.isDarwin [ Carbon Cocoa ]
    ++ lib.optional alsaSupport alsa-lib
    ++ lib.optional pulseSupport libpulseaudio;

  propagatedBuildInputs = lib.optionals stdenv.hostPlatform.isLinux [ libGLU libX11 ]
    ++ lib.optionals stdenv.hostPlatform.isDarwin [ OpenGL ];

  # https://github.com/raysan5/raylib/wiki/CMake-Build-Options
  cmakeFlags = [
    "-DUSE_EXTERNAL_GLFW=ON"
	"-DGLFW_BUILD_X11=ON"
    "-DBUILD_EXAMPLES=OFF"
    "-DCUSTOMIZE_BUILD=ON"
	"-DOPENGL_VERSION=4.3"
  ] ++ lib.optional includeEverything "-DINCLUDE_EVERYTHING=ON"
  ++ lib.optional sharedLib "-DBUILD_SHARED_LIBS=ON";

  passthru.tests = { inherit raylib-games; };

  # fix libasound.so/libpulse.so not being found
  appendRunpaths = lib.optionals stdenv.hostPlatform.isLinux [
    (lib.makeLibraryPath (lib.optional alsaSupport alsa-lib ++ lib.optional pulseSupport libpulseaudio))
  ];

  meta = with lib; {
    description = "Simple and easy-to-use library to enjoy videogames programming";
    homepage = "https://www.raylib.com/";
    license = licenses.zlib;
    maintainers = [ ];
    platforms = platforms.all;
    changelog = "https://github.com/raysan5/raylib/blob/${finalAttrs.version}/CHANGELOG";
  };
})

