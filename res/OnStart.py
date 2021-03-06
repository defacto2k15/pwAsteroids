print("Starting python")
def getRocketActor():
	return next( x for x in getAllActors() if x.getActorType() == "Rocket" )

def RemoveAllActorsOfType( *types):
	for k in types:
		for x in getAllActors() :
			if x.getActorType() in types:
				removeActor( x )

allTypes = ["Rocket", "RocketTail", "Invalid", "Asteroid", "Projectile", "TripleShootPowerup", "HealthPowerup", "ExplosionCloud", "Other"];

def RemoveAllActors():
	RemoveAllActorsOfType(*allTypes)

#disableAsteroidsGeneration()

getConfiguration().RocketAccelerationRate = 0.5
getConfiguration().RocketTurnRate = 0.02
getConfiguration().RocketOppositeAccelerationMultiplyRate = 0.8;
getConfiguration().ExplosionCloudGrowthRatio = 0.08;
getConfiguration().InitialRotation = Rotation(0);

