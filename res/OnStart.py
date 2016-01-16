print("Starting python")
def getRocketActor():
	return next( x for x in getAllActors() if x.getActorType() == "Rocket" )

def RemoveAllActorsOfType( *types):
	for k in types:
		for x in getAllActors()  :
			if x.getActorType() in types:
				removeActor( x )

