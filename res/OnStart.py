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

disableAsteroidsGeneration()

#generateAsteroid( Point(1,1), Rotation(0),1, Point(0,0), 0)
#generateAsteroid( Point(2,1), Rotation(0),1, Point(-2,0), 0)
getConfiguration().RocketAccelerationRate = 0.5
getConfiguration().RocketTurnRate = 0.02
getConfiguration().RocketOppositeAccelerationMultiplyRate = 0.8;
getConfiguration().ExplosionCloudGrowthRatio = 0.08;
getConfiguration().InitialRotation = Rotation(0);


#RemoveAllActors()
#generateAsteroid( Point(0, 2), Rotation(0), 1, Point(0.20, 0), 0)
#generateAsteroid( Point(2, 2), Rotation(0), 1, Point(-0.20, 0), 0)