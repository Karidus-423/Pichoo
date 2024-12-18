{
  description = "Raytracing";

  # Flake inputs
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  # Flake outputs
  outputs = { self, nixpkgs, flake-utils, ... }@inputs:
    flake-utils.lib.eachDefaultSystem (system: 
      let
        pkgs = import nixpkgs { inherit system; };
		rl = import ./raylib/default.nix {
          inherit (pkgs) lib stdenv fetchFromGitHub cmake zig libX11;
        };
      in {
        devShells.default = pkgs.mkShell {
          name = "Raytracing";
          buildInputs = with pkgs; [
            zig
            watchexec
            glsl_analyzer
			rl
          ];
        };
      });
}

