Config = {
	game = "UxiaANecoraDeMontealto",
	debugGame = "UxiaANecoraDeMontealto_d",
	assetsFile = "Assets/assets.forge.lua",
	scenesFile = "Assets/scenes.forge.lua",
	initialScene = "MainMenuScene"
}

Window = {
	width  = 1280,
	height = 768
}

Physics = {
	layers = {	
		--				All		Player	Enemy	Ground	Object DeathZone Attack PlayerAttack
		ALL			= {	true },
		Player		= {	true,	true },
		Enemy		= {	true,	true, 	false },
		Ground		= {	true,	true, 	false,	false },
		Object		= {	true,	true, 	false,	false,	false},
		DeathZone 	= {	true,	true, 	false,	false,	false,	false},
		Attack		= {	true,	false,	true,	false,	false,	false,	false}
	},
	debug = true
}