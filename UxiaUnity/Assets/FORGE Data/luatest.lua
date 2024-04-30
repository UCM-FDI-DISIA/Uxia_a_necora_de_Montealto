local prefabs = {

	Cigarro1= {
		handler = "Cigarro",
		group = "",
		components = {
			Transform= {
				position = {26.65192,-25.68632,0},
				rotation = {0,0,0,1},
				scale = {0.5,1.124932,1}
			},
			Collider= {
				scale = {0.5,1.124932,1},
				shapeType = "Cube",
				layer = "Object"				
			},
			Mesh= {
				mesh = "cigar.mesh"				
			}
		}
	},

	Alga1= {
		handler = "Alga",
		group = "",
		components = {
			Transform= {
				position = {21.01625,-3.271324,0},
				rotation = {0,0,-0.2588186,0.965926},
				scale = {0.4691,1,1}
			},
			Collider= {
				scale = {0.4691,1,1},
				shapeType = "Cylinder"				
			},
			Mesh= {
				mesh = "Cylinder.mesh",
				layer = "Object"				
			},
			KelpComponent= {
				score = 1				
			}
		}
	},
}

local scenes = {
	MapScene = {

		MainCamera= {
			handler = "MainCamera",
			components = {
				Transform= {
					position = {17,1.3,-1},
					rotation = {0,0,0,1},
					scale = {1,1,1}
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

		Player= {
			handler = "Player",
			components = {
				Transform= {
					position = {11.92,-0.67,0},
					rotation = {0,0,0.7071068,0.7071068},
					scale = {1,1,1}
				},
				RigidBody= {
					scale = {1,1,1},
					axisBlocked = {false,false,true,true,true,true},
					mass = 1,
					friction = 1,
					restitution = 1,
					shapeType = "Cube",
					static = false,
					layer = "ALL"					
				}
			}
		},

		Cigarros= {
			components = {
				Transform= {
					position = {0,0,0},
					rotation = {0,0,0,1},
					scale = {0.8751596,0.8751596,0.8751596}
				}
			},
			
			Cigarro1= {
				blueprint = "Cigarro",
				components = {
					Transform= {
						position = {26.65192,-25.68632,0},
						rotation = {0,0,0,1},
						scale = {0.5,1.124932,1}
					}
				}
			},
			
			Cigarro2= {
				blueprint = "Cigarro",
				components = {
					Transform= {
						position = {72.92918,-16.25947,0},
						rotation = {0,0,0,1},
						scale = {0.5,1.124932,1}
					}
				}
			},
			
			Cigarro3= {
				blueprint = "Cigarro",
				components = {
					Transform= {
						position = {71.21521,-2.833354,0},
						rotation = {0,0,0,1},
						scale = {0.5,1.124932,1}
					}
				}
			},
			
			Cigarro4= {
				blueprint = "Cigarro",
				components = {
					Transform= {
						position = {136.6318,-15.68815,0},
						rotation = {0,0,0,1},
						scale = {0.5,1.124932,1}
					}
				}
			}
		},

		Algas= {
			components = {
				Transform= {
					position = {0,0,0},
					rotation = {0,0,0,1},
					scale = {0.8751596,0.8751596,0.8751596}
				}
			},
			
			Alga1= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {21.01625,-3.271324,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga2= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {21.01625,-5.771324,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga3= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {21.01625,-8.45,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga4= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {21.01625,-11.02132,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga5= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {21.01625,-13.73566,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga6= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {21.01625,-16.77132,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga7= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {21.01625,-19.52132,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga8= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {38.15598,-25.80589,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga9= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {41.58393,-22.37794,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga10= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {45.29753,-20.66397,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga11= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {48.43982,-22.66361,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga12= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {51.01078,-26.09155,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga13= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {47.29717,-14.66507,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga14= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {50.43946,-14.66507,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga15= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {53.29608,-14.66507,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga16= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {56.43836,-14.66507,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga17= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {59.58064,-14.66507,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga18= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {90.14649,5.331283,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga19= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {92.71745,5.331283,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga20= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {95.28841,5.331283,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga21= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {97.85938,5.331283,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga22= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {100.716,5.331283,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga23= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {103.0013,5.331283,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga24= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {105.5723,5.331283,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga25= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {97.85938,8.473566,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga26= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {100.716,8.473566,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga27= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {103.0013,8.473566,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga28= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {105.5723,8.473566,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga29= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {97.85938,11.61585,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga30= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {100.716,11.61585,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga31= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {103.0013,11.61585,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga32= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {105.5723,11.61585,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga33= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {82.43362,-14.66507,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga34= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {86.14722,-14.66507,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga35= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {89.86083,-14.66507,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga36= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {93.00311,-14.66507,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga37= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {107.8575,-9.523151,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga38= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {111.5712,-9.523151,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga39= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {114.9991,-9.523151,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga40= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {118.427,-9.523151,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga41= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {109.2859,-20.94964,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga42= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {113.8565,-20.94964,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga43= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {120.4267,-14.37941,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga44= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {120.4267,-16.66471,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga45= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {126.1399,-22.09229,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga46= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {130.1392,-22.09229,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga47= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {148.7072,-16.09338,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga48= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {151.2782,-13.52242,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga49= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {155.8488,-13.52242,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga50= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {158.9911,-16.09338,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga51= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {162.419,-13.52242,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga52= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {166.4183,-13.80808,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga53= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {169.2749,-16.37904,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga54= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {174.9881,-17.52169,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga55= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {178.9874,-19.52133,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga56= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {200.4121,-8.094842,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga57= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {203.84,-8.094842,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga58= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {205.8397,-4.666896,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			},
			
			Alga59= {
				blueprint = "Alga",
				components = {
					Transform= {
						position = {208.9819,-2.381599,0},
						rotation = {0,0,-0.2588186,0.965926},
						scale = {0.4691,1,1}
					}
				}
			}
		},

		Terreno= {
			components = {
				Transform= {
					position = {0,0,0},
					rotation = {0,0,0,1},
					scale = {0.8751596,0.8751596,0.8751596}
				}
			},
			
			Ground= {
				components = {
					Transform= {
						position = {9.157056,-24.1024,0},
						rotation = {0,0,0,1},
						scale = {18.24046,44.89019,1}
					},
					Collider= {
						scale = {18.24046,44.89019,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_1= {
				components = {
					Transform= {
						position = {12.25366,9.957811,0},
						rotation = {0,0,0,1},
						scale = {22.46497,13.35052,1}
					},
					Collider= {
						scale = {22.46497,13.35052,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_2= {
				components = {
					Transform= {
						position = {31.27899,0.1330093,0},
						rotation = {0,0,0.7071068,0.7071068},
						scale = {32.99981,15.58366,1}
					},
					Collider= {
						scale = {32.99981,15.58366,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_3= {
				components = {
					Transform= {
						position = {52.1031,12.70214,0},
						rotation = {0,0,0.7071068,0.7071068},
						scale = {38.716,26.04071,1}
					},
					Collider= {
						scale = {38.716,26.04071,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_15= {
				components = {
					Transform= {
						position = {80.09798,20.41502,0},
						rotation = {0,0,0.7071068,0.7071068},
						scale = {23.28676,30.04056,1}
					},
					Collider= {
						scale = {23.28676,30.04056,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_18= {
				components = {
					Transform= {
						position = {100.9513,23.41448,0},
						rotation = {0,0,0.7071068,0.7071068},
						scale = {17.28721,11.75787,1}
					},
					Collider= {
						scale = {17.28721,11.75787,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_19= {
				components = {
					Transform= {
						position = {119.6622,16.98708,0},
						rotation = {0,0,0.7071068,0.7071068},
						scale = {30.14191,25.75562,1}
					},
					Collider= {
						scale = {30.14191,25.75562,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_25= {
				components = {
					Transform= {
						position = {152.9418,11.84516,0},
						rotation = {0,0,0.7071068,0.7071068},
						scale = {40.42633,40.89478,1}
					},
					Collider= {
						scale = {40.42633,40.89478,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_4= {
				components = {
					Transform= {
						position = {23.38559,-37.37799,0},
						rotation = {0,0,0,1},
						scale = {10.30046,18.32828,1}
					},
					Collider= {
						scale = {10.30046,18.32828,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_5= {
				components = {
					Transform= {
						position = {44.97408,-37.41199,0},
						rotation = {0,0,0,1},
						scale = {20.53343,18.49995,1}
					},
					Collider= {
						scale = {20.53343,18.49995,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_6= {
				components = {
					Transform= {
						position = {65.8516,-35.12669,0},
						rotation = {0,0,0,1},
						scale = {9.725895,23.07129,1}
					},
					Collider= {
						scale = {9.725895,23.07129,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_7= {
				components = {
					Transform= {
						position = {74.25446,-32.55573,0},
						rotation = {0,0,0,1},
						scale = {7.107291,28.21388,1}
					},
					Collider= {
						scale = {7.107291,28.21388,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_9= {
				components = {
					Transform= {
						position = {89.9075,-31.41308,0},
						rotation = {0,0,0,1},
						scale = {24.36362,30.49787,1}
					},
					Collider= {
						scale = {24.36362,30.49787,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_8= {
				components = {
					Transform= {
						position = {53.03754,-17.13,0},
						rotation = {0,0,0,1},
						scale = {16.53437,1.933702,1}
					},
					Collider= {
						scale = {16.53437,1.933702,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_10= {
				components = {
					Transform= {
						position = {81.8894,-10.787,0},
						rotation = {0,0,0,1},
						scale = {22.247,2.050476,1}
					},
					Collider= {
						scale = {22.247,2.050476,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_11= {
				components = {
					Transform= {
						position = {87.17416,-8.845797,0},
						rotation = {0,0,0,1},
						scale = {17.38852,1.933682,1}
					},
					Collider= {
						scale = {17.38852,1.933682,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_16= {
				components = {
					Transform= {
						position = {95.4965,-1.418581,0},
						rotation = {0,0,0,1},
						scale = {22.60653,2.504776,1}
					},
					Collider= {
						scale = {22.60653,2.504776,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_17= {
				components = {
					Transform= {
						position = {91.0688,1.939817,0},
						rotation = {0,0,0,1},
						scale = {31.46238,4.218759,1}
					},
					Collider= {
						scale = {31.46238,4.218759,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_13= {
				components = {
					Transform= {
						position = {73.6636,-7.131825,0},
						rotation = {0,0,0,1},
						scale = {9.792862,5.361515,1}
					},
					Collider= {
						scale = {9.792862,5.361515,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_14= {
				components = {
					Transform= {
						position = {66.95054,-3.65,0},
						rotation = {0,0,0,1},
						scale = {3.793755,5.933552,1}
					},
					Collider= {
						scale = {3.793755,5.933552,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_12= {
				components = {
					Transform= {
						position = {113.7407,-11.55959,0},
						rotation = {0,0,0,1},
						scale = {14.53313,1.648048,1}
					},
					Collider= {
						scale = {14.53313,1.648048,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_20= {
				components = {
					Transform= {
						position = {111.8839,-34.41254,0},
						rotation = {0,0,0,1},
						scale = {9.677046,24.50104,1}
					},
					Collider= {
						scale = {9.677046,24.50104,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_21= {
				components = {
					Transform= {
						position = {120.4,-32.41291,0},
						rotation = {0,0,0,1},
						scale = {7.391328,28.50129,1}
					},
					Collider= {
						scale = {7.391328,28.50129,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_22= {
				components = {
					Transform= {
						position = {127.77,-35.1267,0},
						rotation = {0,0,0,1},
						scale = {7.391328,23.07464,1}
					},
					Collider= {
						scale = {7.391328,23.07464,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_23= {
				components = {
					Transform= {
						position = {127.77,-35.1267,0},
						rotation = {0,0,0,1},
						scale = {7.391328,23.07464,1}
					},
					Collider= {
						scale = {7.391328,23.07464,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_24= {
				components = {
					Transform= {
						position = {138.6252,-32.12724,0},
						rotation = {0,0,0,1},
						scale = {7.391328,29.07405,1}
					},
					Collider= {
						scale = {7.391328,29.07405,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_26= {
				components = {
					Transform= {
						position = {148.4805,-32.12724,0},
						rotation = {0,0,0,1},
						scale = {2.535225,29.07405,1}
					},
					Collider= {
						scale = {2.535225,29.07405,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_27= {
				components = {
					Transform= {
						position = {159.05,-32.12724,0},
						rotation = {0,0,0,1},
						scale = {2.535225,29.07405,1}
					},
					Collider= {
						scale = {2.535225,29.07405,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_28= {
				components = {
					Transform= {
						position = {169.3338,-32.12724,0},
						rotation = {0,0,0,1},
						scale = {2.535225,29.07405,1}
					},
					Collider= {
						scale = {2.535225,29.07405,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_29= {
				components = {
					Transform= {
						position = {179.0463,-33.98405,0},
						rotation = {0,0,0,1},
						scale = {2.535225,25.36129,1}
					},
					Collider= {
						scale = {2.535225,25.36129,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_31= {
				components = {
					Transform= {
						position = {191.6155,-30.98459,0},
						rotation = {0,0,0,1},
						scale = {13.39052,31.36081,1}
					},
					Collider= {
						scale = {13.39052,31.36081,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_32= {
				components = {
					Transform= {
						position = {203.6133,-28.41364,0},
						rotation = {0,0,0,1},
						scale = {11.10504,36.50399,1}
					},
					Collider= {
						scale = {11.10504,36.50399,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_33= {
				components = {
					Transform= {
						position = {215.3254,-25.41418,0},
						rotation = {0,0,0,1},
						scale = {12.8189,42.50159,1}
					},
					Collider= {
						scale = {12.8189,42.50159,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_34= {
				components = {
					Transform= {
						position = {225.0379,-23.12889,0},
						rotation = {0,0,0,1},
						scale = {7.105398,47.07051,1}
					},
					Collider= {
						scale = {7.105398,47.07051,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_30= {
				components = {
					Transform= {
						position = {177.0467,9.341371,0},
						rotation = {0,0,0,1},
						scale = {7.676759,45.35551,1}
					},
					Collider= {
						scale = {7.676759,45.35551,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_35= {
				components = {
					Transform= {
						position = {190.6156,17.05425,0},
						rotation = {0,0,0,1},
						scale = {19.96005,29.9301,1}
					},
					Collider= {
						scale = {19.96005,29.9301,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Ground_36= {
				components = {
					Transform= {
						position = {214.3167,21.48201,0},
						rotation = {0,0,0,1},
						scale = {27.97696,21.07378,1}
					},
					Collider= {
						scale = {27.97696,21.07378,1},
						shapeType = "Cube"						
					}
				}
			},
			
			Cube= {
				components = {
					Transform= {
						position = {0.5262561,7.258011,0},
						rotation = {0,0,0,1},
						scale = {1,18.74993,1}
					},
					Collider= {
						scale = {1,18.74993,1},
						shapeType = "Cube"						
					}
				}
			}
		},

		NecorasMalvadas= {
			components = {
				Transform= {
					position = {0,0,0},
					rotation = {0,0,0,1},
					scale = {1,1,1}
				}
			},
			
			NecoraMalvada_1= {
				group = "",
				components = {
					Transform= {
						position = {39.27,-23.82,0},
						rotation = {0,0,0.7071068,0.7071068},
						scale = {1,1,1}
					},
					Rigidbody= {
						scale = {1,1,1},
						axisBlocked = {false,true,true,true,true,true},
						mass = 1,
						friction = 1,
						restitution = 1,
						shapeType = "Cube",
						static = false,
						layer = "Enemy"						
					},
					Mesh= {
						mesh = "Cylinder.mesh"						
					},
					MovementComponent= {
						jumpForce = 0						
					},
					EnemyComponent= {
						p1 = {31.5,-23.82,0},
						p2 = {47,-23.82,0},
						speed = 30						
					}
				}
			},
			
			NecoraMalvada_6= {
				group = "",
				components = {
					Transform= {
						position = {46.77,-13.32,0},
						rotation = {0,0,0.7071068,0.7071068},
						scale = {1,1,1}
					},
					Rigidbody= {
						scale = {1,1,1},
						axisBlocked = {false,true,true,true,true,true},
						mass = 1,
						friction = 1,
						restitution = 1,
						shapeType = "Cube",
						static = false,
						layer = "Enemy"						
					},
					Mesh= {
						mesh = "Cylinder.mesh"						
					},
					MovementComponent= {
						jumpForce = 0						
					},
					EnemyComponent= {
						p1 = {41,-13.32,0},
						p2 = {52,-13.32,0},
						speed = 30						
					}
				}
			},
			
			NecoraMalvada_7= {
				group = "",
				components = {
					Transform= {
						position = {76.77,-13.38,0},
						rotation = {0,0,0.7071068,0.7071068},
						scale = {1,1,1}
					},
					Rigidbody= {
						scale = {1,1,1},
						axisBlocked = {false,true,true,true,true,true},
						mass = 1,
						friction = 1,
						restitution = 1,
						shapeType = "Cube",
						static = false,
						layer = "Enemy"						
					},
					Mesh= {
						mesh = "Cylinder.mesh"						
					},
					MovementComponent= {
						jumpForce = 0						
					},
					EnemyComponent= {
						p1 = {70,-13.38,0},
						p2 = {87,-13.38,0},
						speed = 30						
					}
				}
			},
			
			NecoraMalvada_4= {
				group = "",
				components = {
					Transform= {
						position = {76.02,-6.13,0},
						rotation = {0,0,0.7071068,0.7071068},
						scale = {1,1,1}
					},
					Rigidbody= {
						scale = {1,1,1},
						axisBlocked = {false,true,true,true,true,true},
						mass = 1,
						friction = 1,
						restitution = 1,
						shapeType = "Cube",
						static = false,
						layer = "Enemy"						
					},
					Mesh= {
						mesh = "Cylinder.mesh"						
					},
					MovementComponent= {
						jumpForce = 0						
					},
					EnemyComponent= {
						p1 = {82,-6.13,0},
						p2 = {70,-6.13,0},
						speed = 30						
					}
				}
			},
			
			NecoraMalvada_3= {
				group = "",
				components = {
					Transform= {
						position = {76.52,4.31,0},
						rotation = {0,0,0.7071068,0.7071068},
						scale = {1,1,1}
					},
					Rigidbody= {
						scale = {1,1,1},
						axisBlocked = {false,true,true,true,true,true},
						mass = 1,
						friction = 1,
						restitution = 1,
						shapeType = "Cube",
						static = false,
						layer = "Enemy"						
					},
					Mesh= {
						mesh = "Cylinder.mesh"						
					},
					MovementComponent= {
						jumpForce = 0						
					},
					EnemyComponent= {
						p1 = {68,4.31,0},
						p2 = {91,4.31,0},
						speed = 30						
					}
				}
			},
			
			NecoraMalvada= {
				group = "",
				components = {
					Transform= {
						position = {99.77,-8.69,0},
						rotation = {0,0,0.7071068,0.7071068},
						scale = {1,1,1}
					},
					Rigidbody= {
						scale = {1,1,1},
						axisBlocked = {false,true,true,true,true,true},
						mass = 1,
						friction = 1,
						restitution = 1,
						shapeType = "Cube",
						static = false,
						layer = "Enemy"						
					},
					Mesh= {
						mesh = "Cylinder.mesh"						
					},
					MovementComponent= {
						jumpForce = 0						
					},
					EnemyComponent= {
						p1 = {95,-8.69,0},
						p2 = {104,-8.69,0},
						speed = 30						
					}
				}
			},
			
			NecoraMalvada_2= {
				group = "",
				components = {
					Transform= {
						position = {167.84,-12.67,0},
						rotation = {0,0,0.7071068,0.7071068},
						scale = {1,1,1}
					},
					Rigidbody= {
						scale = {1,1,1},
						axisBlocked = {false,true,true,true,true,true},
						mass = 1,
						friction = 1,
						restitution = 1,
						shapeType = "Cube",
						static = false,
						layer = "Enemy"						
					},
					Mesh= {
						mesh = "Cylinder.mesh"						
					},
					MovementComponent= {
						jumpForce = 0						
					},
					EnemyComponent= {
						p1 = {164,-12.67,0},
						p2 = {171,-12.67,0},
						speed = 30						
					}
				}
			},
			
			NecoraMalvada_5= {
				group = "",
				components = {
					Transform= {
						position = {188.59,-2.92,0},
						rotation = {0,0,0.7071068,0.7071068},
						scale = {1,1,1}
					},
					Rigidbody= {
						scale = {1,1,1},
						axisBlocked = {false,true,true,true,true,true},
						mass = 1,
						friction = 1,
						restitution = 1,
						shapeType = "Cube",
						static = false,
						layer = "Enemy"						
					},
					Mesh= {
						mesh = "Cylinder.mesh"						
					},
					MovementComponent= {
						jumpForce = 0						
					},
					EnemyComponent= {
						p1 = {184,-2.92,0},
						p2 = {192,-2.92,0},
						speed = 30						
					}
				}
			}
		},

		Tentaculos= {
			components = {
				Transform= {
					position = {0,0,0},
					rotation = {0,0,0,1},
					scale = {1,1,1}
				}
			},
			
			Huecos= {
				components = {
					Transform= {
						position = {0,0,0},
						rotation = {0,0,0,1},
						scale = {1,1,1}
					}
				},
				
				HuecoTentaculo= {
					components = {
						Transform= {
							position = {50.8516,-40.29,0},
							rotation = {0,0,0,1},
							scale = {4.581482,1,1}
						}
					}
				},
				
				HuecoTentaculo_1= {
					components = {
						Transform= {
							position = {91.3516,-40.29,0},
							rotation = {0,0,0,1},
							scale = {4.581482,1,1}
						}
					}
				},
				
				HuecoTentaculo_2= {
					components = {
						Transform= {
							position = {112.3516,1.1,0},
							rotation = {0,0,0,1},
							scale = {4.581482,1,1}
						}
					}
				},
				
				HuecoTentaculo_3= {
					components = {
						Transform= {
							position = {126.6016,-40.29,0},
							rotation = {0,0,0,1},
							scale = {4.581482,1,1}
						}
					}
				},
				
				HuecoTentaculo_4= {
					components = {
						Transform= {
							position = {134.6016,-40.29,0},
							rotation = {0,0,0,1},
							scale = {4.581482,1,1}
						}
					}
				},
				
				HuecoTentaculo_5= {
					components = {
						Transform= {
							position = {143.8516,-40.29,0},
							rotation = {0,0,0,1},
							scale = {4.581482,1,1}
						}
					}
				},
				
				HuecoTentaculo_6= {
					components = {
						Transform= {
							position = {152.6016,-40.29,0},
							rotation = {0,0,0,1},
							scale = {4.581482,1,1}
						}
					}
				},
				
				HuecoTentaculo_7= {
					components = {
						Transform= {
							position = {152.6016,-40.29,0},
							rotation = {0,0,0,1},
							scale = {4.581482,1,1}
						}
					}
				},
				
				HuecoTentaculo_8= {
					components = {
						Transform= {
							position = {182.1016,-6.290001,0},
							rotation = {0,0,0.7071068,0.7071068},
							scale = {4.581482,1,1}
						}
					}
				},
				
				HuecoTentaculo_9= {
					components = {
						Transform= {
							position = {178.8516,8.709999,0},
							rotation = {0,0,0,1},
							scale = {4.581482,1,1}
						}
					}
				}
			},
			
			Tentaculos= {
				components = {
					Transform= {
						position = {0,0,0},
						rotation = {0,0,0,1},
						scale = {1,1,1}
					}
				},
				
				Tentaculo= {
					components = {
						Transform= {
							position = {112.31,4.1,-0.5006065},
							rotation = {0,0,0,1},
							scale = {3,9,1}
						},
						Rigidbody= {
							scale = {3,9,1},
							axisBlocked = {false,false,true,true,true,true},
							mass = 0,
							friction = 1,
							restitution = 1,
							shapeType = "Cube",
							static = false,
							layer = "Enemy"							
						},
						Mesh= {
							mesh = "Cylinder.mesh"							
						},
						EnemyComponent= {
							p1 = {112.3,-8.4,0},
							p2 = {112.3, 2.7,0},
							speed = 30							
						},
						MovementComponent= {
							jumpForce = 0							
						}
					}
				},
				
				Tentaculo_1= {
					components = {
						Transform= {
							position = {50.8,-34.2,-0.5006065},
							rotation = {0,0,0,1},
							scale = {3,11.3,1}
						},
						Rigidbody= {
							scale = {3,11.3,1},
							axisBlocked = {false,false,true,true,true,true},
							mass = 0,
							friction = 1,
							restitution = 1,
							shapeType = "Cube",
							static = false,
							layer = "Enemy"							
						},
						Mesh= {
							mesh = "Cylinder.mesh"							
						},
						EnemyComponent= {
							p1 = {50.8,-21.4,0},
							p2 = {50.8,-37.2,0},
							speed = 30							
						},
						MovementComponent= {
							jumpForce = 0							
						}
					}
				},
				
				Tentaculo_2= {
					components = {
						Transform= {
							position = {91.5,-30.3,-0.5006065},
							rotation = {0,0,0,1},
							scale = {3,18,1}
						},
						Rigidbody= {
							scale = {3,18,1},
							axisBlocked = {false,false,true,true,true,true},
							mass = 0,
							friction = 1,
							restitution = 1,
							shapeType = "Cube",
							static = false,
							layer = "Enemy"							
						},
						Mesh= {
							mesh = "Cylinder.mesh"							
						},
						EnemyComponent= {
							p1 = {91.5,-21.7,0},
							p2 = {91.5,-40.4,0},
							speed = 30							
						},
						MovementComponent= {
							jumpForce = 0							
						}
					}
				},
				
				Tentaculo_3= {
					components = {
						Transform= {
							position = {126.7,-33.5,-0.5006065},
							rotation = {0,0,0,1},
							scale = {3,16,1}
						},
						Rigidbody= {
							scale = {3,16,1},
							axisBlocked = {false,false,true,true,true,true},
							mass = 0,
							friction = 1,
							restitution = 1,
							shapeType = "Cube",
							static = false,
							layer = "Enemy"							
						},
						Mesh= {
							mesh = "Cylinder.mesh"							
						},
						EnemyComponent= {
							p1 = {126.7,-24.3,0},
							p2 = {126.7,-36,0},
							speed = 30							
						},
						MovementComponent= {
							jumpForce = 0							
						}
					}
				},
				
				Tentaculo_4= {
					components = {
						Transform= {
							position = {134.7,-29.5,-0.5006065},
							rotation = {0,0,0,1},
							scale = {3,16,1}
						},
						Rigidbody= {
							scale = {3,16,1},
							axisBlocked = {false,false,true,true,true,true},
							mass = 0,
							friction = 1,
							restitution = 1,
							shapeType = "Cube",
							static = false,
							layer = "Enemy"							
						},
						Mesh= {
							mesh = "Cylinder.mesh"							
						},
						EnemyComponent= {
							p1 = {134.7,-24.3,0},
							p2 = {134.7,-36,0},
							speed = 30							
						},
						MovementComponent= {
							jumpForce = 0							
						}
					}
				},
				
				Tentaculo_5= {
					components = {
						Transform= {
							position = {143.7,-25.1,-0.5006065},
							rotation = {0,0,0,1},
							scale = {3,16,1}
						},
						Rigidbody= {
							scale = {3,16,1},
							axisBlocked = {false,false,true,true,true,true},
							mass = 0,
							friction = 1,
							restitution = 1,
							shapeType = "Cube",
							static = false,
							layer = "Enemy"							
						},
						Mesh= {
							mesh = "Cylinder.mesh"							
						},
						EnemyComponent= {
							p1 = {143.7,-24.3,0},
							p2 = {143.7,-36,0},
							speed = 30							
						},
						MovementComponent= {
							jumpForce = 0							
						}
					}
				},
				
				Tentaculo_6= {
					components = {
						Transform= {
							position = {152.6,-32.8,-0.5006065},
							rotation = {0,0,0,1},
							scale = {3,14,1}
						},
						Rigidbody= {
							scale = {1,14,1},
							axisBlocked = {false,false,true,true,true,true},
							mass = 0,
							friction = 1,
							restitution = 1,
							shapeType = "Cube",
							static = false,
							layer = "Enemy"							
						},
						Mesh= {
							mesh = "Cylinder.mesh"							
						},
						EnemyComponent= {
							p1 = {152.6,-26.6,0},
							p2 = {152.6,-35.5,0},
							speed = 30							
						},
						MovementComponent= {
							jumpForce = 0							
						}
					}
				},
				
				Tentaculo_7= {
					components = {
						Transform= {
							position = {186.9,-6.3,-0.5006065},
							rotation = {0,0,0.7071068,0.7071068},
							scale = {3,11.3,1}
						},
						Rigidbody= {
							scale = {3,11.3,1},
							axisBlocked = {false,false,true,true,true,true},
							mass = 0,
							friction = 1,
							restitution = 1,
							shapeType = "Cube",
							static = false,
							layer = "Enemy"							
						},
						Mesh= {
							mesh = "Cylinder.mesh"							
						},
						EnemyComponent= {
							p1 = {171,-6.3,0},
							p2 = {193,-6.3,0},
							speed = 30							
						},
						MovementComponent= {
							jumpForce = 0							
						}
					}
				},
				
				Tentaculo_8= {
					components = {
						Transform= {
							position = {178.8,0.4064,-0.5006065},
							rotation = {0,0,0,1},
							scale = {3,8.3,1}
						},
						Rigidbody= {
							scale = {3,8.3,1},
							axisBlocked = {false,false,true,true,true,true},
							mass = 0,
							friction = 1,
							restitution = 1,
							shapeType = "Cube",
							static = false,
							layer = "Enemy"							
						},
						Mesh= {
							mesh = "Cylinder.mesh"							
						},
						EnemyComponent= {
							p1 = {178,0.4,0},
							p2 = {178,15.6,0},
							speed = 30							
						},
						MovementComponent= {
							jumpForce = 0							
						}
					}
				}
			}
		},

		Cube= {
			components = {
				Transform= {
					position = {192.72,-3.02,0},
					rotation = {0,0,0,1},
					scale = {1,1,1}
				}
			}
		},

		DeathZones= {
			components = {
				Transform= {
					position = {161.3,-26.1,-1.018157},
					rotation = {0,0,0,1},
					scale = {1,1,1}
				}
			},
			
			DeathZone= {
				components = {
					Transform= {
						position = {-124.4548,-6.4,0},
						rotation = {0,0,0,1},
						scale = {53,7.34,1}
					},
					Collider= {
						scale = {53, 7.34,1},
						shapeType = "Cube",
						layer = "DeathZone"						
					}
				}
			},
			
			DeathZone_1= {
				components = {
					Transform= {
						position = {-64.5,-2.4,0},
						rotation = {0,0,0,1},
						scale = {53,7.34,1}
					},
					Collider= {
						scale = {53, 7.34,1},
						shapeType = "Cube",
						layer = "DeathZone"						
					}
				}
			},
			
			DeathZone_2= {
				components = {
					Transform= {
						position = {-26.8311,2.700001,0},
						rotation = {0,0,0,1},
						scale = {27,7.34,1}
					},
					Collider= {
						scale = {27, 7.34,1},
						shapeType = "Cube",
						layer = "DeathZone"						
					}
				}
			},
			
			DeathZone_3= {
				components = {
					Transform= {
						position = {0,0,0},
						rotation = {0,0,0,1},
						scale = {27,7.34,1}
					},
					Collider= {
						scale = {27, 7.34,1},
						shapeType = "Cube",
						layer = "DeathZone"						
					}
				}
			}
		}
	}	
}
return prefabs, scenes