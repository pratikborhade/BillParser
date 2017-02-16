.PHONY: clean All

All:
	@echo "----------Building project:[ Core - Debug ]----------"
	@cd "Core" && "$(MAKE)" -f  "Core.mk"
clean:
	@echo "----------Cleaning project:[ Core - Debug ]----------"
	@cd "Core" && "$(MAKE)" -f  "Core.mk" clean
