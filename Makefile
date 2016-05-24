.PHONY: clean All

All:
	@echo "----------Building project:[ Week_2_vector -  ]----------"
	@cd "Week_2_vector" && "$(MAKE)" -f  "Week_2_vector.mk"
clean:
	@echo "----------Cleaning project:[ Week_2_vector -  ]----------"
	@cd "Week_2_vector" && "$(MAKE)" -f  "Week_2_vector.mk" clean
