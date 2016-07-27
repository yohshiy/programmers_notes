;; 
;; キーの設定
;; 

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; 移動コマンド
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; 上下は C-p, C-n (そのまま)
;; 左右は C-k, C-l
(global-set-key "\C-l" "\C-f")
(global-set-key "\C-k" "\C-b")

;; (keyboard-translate ?\C-l ?\C-f)
;; (keyboard-translate ?\C-k ?\C-b)


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; 基本的なコマンド
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; あまり使ってないキーの割り当て

(global-set-key "\C-o" 'dabbrev-expand)
(global-set-key "\C-z" 'undo)



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; ファンクション(F)キー
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; F7  コンパイル
;; F8  eshell

(global-set-key (kbd "<f7>") 'compile)
(global-set-key (kbd "<f8>") 'eshell)




;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; あまり使わない文字(@)をトリガーとしたキーマップ
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defvar my-atkey-prefix (kbd "@"))

(setq my-atkey-map (make-keymap))
(define-key global-map my-atkey-prefix my-atkey-map)

(defun my-set-key-atkey-map ()
  (local-set-key my-atkey-prefix my-atkey-map))
(add-hook `hexl-mode-hook 'my-set-key-atkey-map)
(add-hook `view-mode-hook 'my-set-key-atkey-map)
(add-hook `ediff-keymap-setup-hook '(lambda ()
				      (define-key ediff-mode-map my-atkey-prefix my-atkey-map)))

;;;;

;; ヘルプ
(define-key my-atkey-map "h" 'help-command)


;; カーソル移動
(define-key my-atkey-map "a" 'beginning-of-line)
(define-key my-atkey-map "e" 'end-of-line)

(define-key my-atkey-map "p" 'beginning-of-buffer)
(define-key my-atkey-map "n" 'end-of-buffer)

(define-key my-atkey-map "l" 'recenter)
(define-key my-atkey-map "j" 'goto-line)


;; コマンド呼び出し
(define-key my-atkey-map " " 'execute-extended-command)



;; ファイル
(define-key my-atkey-map "f" 'find-file)
(define-key my-atkey-map "s" 'save-buffer)
(define-key my-atkey-map "w" 'write-file)
(define-key my-atkey-map "F" 'set-buffer-file-coding-system)

;; バッファー
(define-key my-atkey-map "d" 'kill-buffer)
(define-key my-atkey-map "b" 'switch-to-buffer)
(define-key my-atkey-map "\C-b" 'list-buffers)

;; Window
(define-key my-atkey-map "o" 'other-window)
(define-key my-atkey-map "2" 'split-window-vertically)
(define-key my-atkey-map "1" 'delete-other-windows)
(define-key my-atkey-map "." 'delete-other-windows)
(define-key my-atkey-map "0" 'delete-window)



;; クリップボード
(define-key my-atkey-map "c" 'kill-ring-save)
(define-key my-atkey-map "x" 'kill-region)
(define-key my-atkey-map "k" 'kill-line)

;; Ctrl-x r
(define-key my-atkey-map "r" ctl-x-r-map)
(define-key my-atkey-map "C" 'copy-to-register)
(define-key my-atkey-map "y" 'insert-register)


;; 検索、置換
(define-key my-atkey-map "m" 'isearch-forward)
(define-key my-atkey-map "u" 'isearch-backward)
(define-key my-atkey-map "q" 'query-replace)
(define-key my-atkey-map "5" 'query-replace-regexp)


;; プログラミング
(define-key my-atkey-map "\t" "\M-\t")
(define-key my-atkey-map "t" 'indent-region)
(define-key my-atkey-map ";" 'comment-region)


;; キーボードマクロ
(define-key my-atkey-map "8" 'kmacro-start-macro)
(define-key my-atkey-map "9" 'kmacro-end-macro)
(define-key my-atkey-map "7" 'kmacro-end-and-call-macro)



;; その他
(define-key my-atkey-map "+" 'make-directory)
(define-key my-atkey-map "z" 'suspend-frame)


;; 占有したキーの代替
(define-key my-atkey-map my-atkey-prefix '(lambda () (interactive) (insert "@")))

