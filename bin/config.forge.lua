Config = {
	game = "UxiaANecoraDeMontealto",
	debugGame = "UxiaANecoraDeMontealto_d",
	assetsFile = "Assets/assets.forge.lua",
	scenesFile = "Assets/scenes.forge.lua",
	initialScene = "MainScene"
}

Physics = {
	layers = {	--		Default	Layer1	Layer2	Layer3
		--Layer3	= {	false,	false,	false,	true},
		--Layer2	= {	true,	false,	true},
		--Layer1	= {	true,	false},
		--				All		Player	Enemy	Ground	Object DeathZone
		ALL			= {	true },
		Player		= {	true,	true },
		Enemy		= {	true,	true, 	false },
		Ground		= {	true,	true, 	false,	false },
		Object		= {	true,	true, 	false,	true,	true},
		DeathZone 	= {	true,	true, 	false,	false,	false,	false}
	},
	debug = true
}