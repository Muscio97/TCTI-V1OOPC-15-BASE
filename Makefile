.PHONY: clean All

All:
	@echo "----------Building project:[ Week_3_victem -  ]----------"
	@cd "Week_3_victem" && "$(MAKE)" -f  "Week_3_victem.mk"
clean:
	@echo "----------Cleaning project:[ Week_3_victem -  ]----------"
	@cd "Week_3_victem" && "$(MAKE)" -f  "Week_3_victem.mk" clean
