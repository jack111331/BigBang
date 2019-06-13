CharacterList = BartCassidy BlackJack ElGringo VultureSam SuzyLafayette RoseDoolan PaulRegret WillyTheKid GodDeveloper

CharacterBuildList = $(foreach NewFilenameWithDir,$(CharacterList), ./Character/$(NewFilenameWithDir))
