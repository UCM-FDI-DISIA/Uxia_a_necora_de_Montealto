local prefabs = {
}

local scenes = {
	MainScene = {

		MainCamera= {
			handler = "MainCamera",
			components = {
				Transform= {
					position = {0,2.57,-22.38},
					rotation = {0,0,0,1},
					scale = {1,1,1}
				},
				Camera= {
					name = maincam,
					nearClipDistance = 1,
					autoAspectRatio = true,
					backgroundColor = {0.6,0.3,0.3}					
				}
			}
		},

		DirectionalLight= {
			components = {
				Transform= {
					position = {0,3,0},
					rotation = {0.4082179,-0.2345697,0.1093816,0.8754261},
					scale = {1,1,1}
				}
			}
		},

		Ground= {
			components = {
				Transform= {
					position = {0,-1.77,0.03},
					rotation = {0,0,0,1},
					scale = {10.675,1,1}
				},
				Collider= {
					scale = {30,5,30},
					shapeType = "Cube"					
				},
				KelpComponent = {
					score = 5
				}
			}
		},

		Enemy= {
			components = {
				Transform= {
					position = {0,0,-50},
					rotation = {0,0,0,0},
					scale = {0.05,0.05,0.05}
				},
				RigidBody= {
					scale = {1,1,1},
					mass = 1,
					friction = 1,
					restitution = 1,
					shapeType = "Cube",
					static = false,
					layer = "ALL"					
				},
				Collider= {
					scale = {1,1,1},
					shapeType = "Cube"					
				},
				MovementComponent = {
					jumpForce = 1
				},
				EnemyComponent = {
					damage = 1,
					radius = 2,
					p1 = {-100, 0, 0},
					p2 = {100, 0, 0}
				},
				Mesh = {
					mesh = "cigar.mesh";
				}
			}
		},

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
					static = true,
					layer = "ALL"					
				},
				Collider= {
					scale = {5,5,5},
					shapeType = "Cube"					
				}
			}
		}
	}	
}
return prefabs, scenes