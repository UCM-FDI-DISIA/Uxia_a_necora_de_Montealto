local prefabs = {
    player = {
        handler = "player",
        components = {
            Transform = {
                position = {0, -20, 0},
                scale = {0.25, 0.25, 0.25}
            },
            RigidBody = {
                scale = {1, 1, 1},
                mass = 1,
                friction = 4,
                restitution = 1,
                shapeType = "Cube",
                static = false,
                layer = "ALL",
                constrain = {false,false,true,true,true,true}
            },
            MovementComponent = {
                jumpForce = 500
            },
            PlayerInputComponent = 0
        }
    }
}

local scenes = {
    MainScene = {
        jugador = {
            blueprint = "player",
            children = {
                cam = {
            components = {
                Transform = {
                    position = {0, 0, 90}
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
        cube={
            components ={
            Transform = {
                position = {0, 0, 0},
                scale = {0.25, 0.25, 0.25}
            },
            RigidBody = {
                scale = {1, 1, 1},
                mass = 1,
                friction = 4,
                restitution = 1,
                shapeType = "Cube",
                static = false,
                layer = "ALL",
                constrain = {true,true,true,true,true,true}
            }
            }
        },
        
        ground = {
            handler = "ground",
            components = {
                Transform = {
                    position = {0, -50, 0},
                    rotation = {0, 0, 0, 1}
                },
                 Collider = {
                    scale = {30, 10, 30},
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