.PHONY: help submodule-update submodule-pull submodule-clean submodule-status

help:
	@printf '%s\n' "Targets:"
	@printf '%s\n' "  make submodule-update  - init/update submodules to the recorded commits"
	@printf '%s\n' "  make submodule-pull    - fetch and fast-forward submodules to their remote tracking branches"
	@printf '%s\n' "  make submodule-clean   - remove all local submodule working trees"
	@printf '%s\n' "  make submodule-status  - show submodule status"

submodule-update:
	git submodule sync --recursive
	git submodule update --init --recursive

submodule-pull:
	git submodule sync --recursive
	git submodule update --remote --merge --recursive

submodule-clean:
	@paths="$$(git config -f .gitmodules --get-regexp path | awk '{print $$2}')"; \
	if [ -n "$$paths" ]; then \
		for path in $$paths; do \
			rm -rf "$$path"; \
		done; \
	fi

submodule-status:
	git submodule status --recursive