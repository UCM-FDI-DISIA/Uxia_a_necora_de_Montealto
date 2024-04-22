local prefabs = {
}

local scenes = {
	MainScene = {

		Main Camera= {
			handler = "MainCamera",
			components = {
				Transform= {
					position = {0,1,-10},
					rotation = {0,0,0,1},
					scale = {1,1,1}
				}
			}
		}

		Ground= {
			components = {
				Transform= {
					position = {0,-1.77,0.03},
					rotation = {0,0,0,1},
					scale = {10.675,1,1}
				},
				Collider= {
					scale = {30,10,30},
					shapeType = "Cube"					
				}
			}
		}

		Player= {
			handler = "Player",
			components = {
				Transform= {
					position = {-2.76,-0.12,0.03},
					rotation = {0,0,0,1},
					scale = {1,1,1}
				},
				RigidBody= {
					scale = {5,5,5},
					mass = 1,
					friction = 1,
					restitution = 1,
					shapeType = "Cube",
					static = false,
					layer = "ALL"					
				}
			}
		}
	}	
}
return prefabs, scenes