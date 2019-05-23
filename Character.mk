CharacterList = BartCassidy BlackJack ElGringo VultureSam SuzyLafayette RoseDoolan PaulRegret WillyTheKid

CharacterBuildList = $(foreach NewFilenameWithDir,$(CharacterList), ./Character/$(NewFilenameWithDir))
