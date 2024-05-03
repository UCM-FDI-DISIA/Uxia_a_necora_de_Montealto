local prefabs = {
    player = {
        handler = "uxia",
        components = {
            Transform = {
                position = {0, 100, 0},
                scale = {0.25, 0.25, 0.25}
            },
            RigidBody = {
                scale = {0.25, 0.25, 0.25},
                mass = 1,
                friction = 2,
                restitution = 1,
                shapeType = "Cube",
                static = false,
                layer = "ALL",
                axisBlocked = {false,false,true,true,true,true}
            },
            MovementComponent = {
                jumpForce = 500
            },
            PlayerInputComponent = {
                speed = 10
            }
        }
    }
}

local scenes = {
	MainScene = {
		luz = {
            components = {
                Transform = {
                    position = {20, 80, 0}
                },
                Light = {
                    type = 0 
                }
            }
		},
		Player= {
			handler = "Player",
			components = {
				Transform= {
					position = {0,0,0},
					rotation = {0,0,0,1},
					scale = {1,1,1}
				},
				RigidBody= {
				 	scale = {1,1,1},
				 	axisBlockedPos = {false,false,true},
				 	axisBlockedRot = {true,true,true},
				 	mass = 1,
				 	friction = 1,
				 	restitution = 1,
				 	shapeType = "Cube",
				 	static = false,
				 	layer = "ALL"					
				},
				Mesh = {
                    mesh = "Cylinder.mesh"

                },
                PlayerInputComponent = {
                     speed = 1
                 },
                 MovementComponent = {
                     jumpForce = 500
                 }
			},
            children = {
                cam = {
                    components = {
                        Transform = {
                            position = {0, 0, 20}
                        },
                        Camera = {
                            nearClipDistance = 1,
                            autoAspectRatio = true,
                            backgroundColor = {0.6, 0.3, 0.3}
                        },
                        AudioListener = 0
                    }
                }
            }
        },

        

        checkpoint = {
            components = {
                Transform = {
                    position = {-5, 15, 0},
                    scale = {0.1, 0.1, 0.1}
                },
                Collider = {
                    scale = {1, 5, 1},
                    trigger = true,
                    shapeType = "Cube"
                },
                CheckpointComponent = {
                    respawnpoint = {-5, 15, 0}
                },
                Mesh = {
                    mesh = "cigar.mesh"
                }
            }
        },

        ground = {
            handler = "ground",
            components = {
                Transform = {
                    position = {0, -10, 0},
                    rotation = {0, 0, 0, 1}
                },
                Collider = {
                    scale = {1, 1, 1},
                    shapeType = "Cube"
                }
            }
        },
        luz = {
            components = {
                Transform = {
                    position = {20, 80, 0}
                },
                Light = {
                    type = 0 
                }
            }
        }
    }
}

return prefabs, scenes
