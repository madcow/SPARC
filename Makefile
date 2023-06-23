.PHONY: todo
todo:
	@echo "Entries marked TODO found:"
	@grep -hr ^TODO #| cut -d ' ' -f2-
