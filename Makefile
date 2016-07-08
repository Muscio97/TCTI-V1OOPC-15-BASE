.PHONY: clean All

All:
	@echo "----------Building project:[ Opdracht_1_2 -  ]----------"
	@cd "Opdracht_1_2" && "$(MAKE)" -f  "Opdracht_1_2.mk"
clean:
	@echo "----------Cleaning project:[ Opdracht_1_2 -  ]----------"
	@cd "Opdracht_1_2" && "$(MAKE)" -f  "Opdracht_1_2.mk" clean
