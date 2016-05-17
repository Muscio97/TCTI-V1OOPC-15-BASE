.PHONY: clean All

All:
	@echo "----------Building project:[ 13-01-rational -  ]----------"
	@cd "13-01-rational" && "$(MAKE)" -f  "13-01-rational.mk"
clean:
	@echo "----------Cleaning project:[ 13-01-rational -  ]----------"
	@cd "13-01-rational" && "$(MAKE)" -f  "13-01-rational.mk" clean
