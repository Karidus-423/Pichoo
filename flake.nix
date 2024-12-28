{
  description = "Raylib development environment";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
  };

  outputs = { self , nixpkgs ,... }@inputs: 
  let
    system = "x86_64-linux";
	pkgs = nixpkgs.legacyPackages.${system};
	rl = pkgs.callPackage ./raylib/raylib.nix {};
  in 
  {
	devShells.${system}.default = pkgs.mkShell {
		name = "Graphics";
		buildInputs = [
		rl
		pkgs.raygui
		];
	};
  };
}
