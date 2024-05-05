((nil (eval . (progn
		(add-to-list 'reason-mode-hook 'esy-mode)
		(add-to-list 'tuareg-mode-hook 'esy-mode)
		;; (remove-hook 'reason-mode-hook 'esy-mode)
		(add-to-list 'before-save-hook 'lsp-format-buffer)
		;; (remove-hook 'before-save-hook 'lsp-format-buffer)
		(setq compile-command "esy dune build -w")))))
