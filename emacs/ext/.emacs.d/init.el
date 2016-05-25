
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; 
;; カスタマイズ
;; 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; カスタマイズ用のファイルを設定
(setq custom-file "~/.emacs.d/custom_setttings.el")

;; カスタマイズ用ファイルをロード
(when (file-exists-p custom-file)
  (load custom-file))


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; 初期表示位置、サイズ
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(setq initial-frame-alist
      '((width . 150)			; サイズ(幅)
	(height . 50)			; サイズ(高さ)
	))



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; 
;; Tips
;; 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; ベル音禁止
(setq ring-bell-function 'ignore)


;; スタート画面(メッセージ)を表示しない
(setq inhibit-startup-screen t)


;; 領域選択時、削除キーで一括削除
(delete-selection-mode t)


;; 行頭で kill-line (C-k) で行全体で削除
(setq kill-whole-line t)


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; 日本語の設定
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; 環境に合わせた日本語文字コードに設定
;;  Windows => SJIS
;;  Linux => 環境変数 LANG から
(set-language-environment "Japanese")

;; ファイルの文字コードだけ BOM 付き UTF-8
(set-default 'buffer-file-coding-system 'utf-8-with-signature)



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; キー設定
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; Windows の場合、 IME の変換でエラーがでないようにする
(when (eq system-type 'windows-nt)
  (global-set-key [M-kanji] 'ignore)
  (global-set-key [kanji] 'ignore)
  )


;; ターミナルの場合(window-system が nil)、
;; <backspace> が C-h になるため、 C-h で一文字削除に設定
(unless window-system
  (global-set-key "\C-h" 'delete-backward-char)             ;; 全般
  (define-key isearch-mode-map "\C-h" 'isearch-delete-char) ;; インクリメンタルサーチ用
  (add-hook 'c-mode-common-hook
	    '(lambda ()
	       (local-set-key "\C-h" 'c-electric-delete)))  ;; C 言語系モード
  )
(global-set-key (kbd "M-?") 'help-command) ; ヘルプキーを変更



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; 
;; 検索、置換時の大文字、小文字の区別
;; 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; オプションの "Ignore Case for Search" で設定可
;;
;; ;; 検索(全般)
;; (setq case-fold-search t)
;;
;; ;; インクリメンタルサーチ
;; (setq isearch-case-fold-search nil)


;; バッファー名の検索
(setq read-buffer-completion-ignore-case t)

;; ファイル名の検索
(setq read-file-name-completion-ignore-case t)


;;;置換(全般)
;; (setq case-replace t)

;; dabbrev 時の置換
(setq dabbrev-case-replace nil)



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; 
;; 自動作成ファイル
;; 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


;; backup ファイルオープン時のバックアップ (xxx~)
;; -------------------------------------------

;; 実行の有無
(setq make-backup-files t)

;; 格納ディレクトリーの変更
;;   (対象ディレクトリー . 格納ディレクトリー) のリスト
(setq backup-directory-alist '((".*" . "~/.ehist")))


;; 番号付けによる複数保存
(setq version-control     t)  ;; 実行の有無
(setq kept-new-versions   5)  ;; 最新の保持数
(setq kept-old-versions   1)  ;; 最古の保持数
(setq delete-old-versions t)  ;; 範囲外を削除



;; auto-save 自動保存ファイル (#xxx#)
;; -------------------------------------------

;; ;; 実行の有無
;; (setq auto-save-default nil)

;; ;; 格納ディレクトリーの変更
;; ;;   (対象ファイルのパターン . 保存ファイルパス) のリスト
;; (setq auto-save-file-name-transforms
;;       (append auto-save-file-name-transforms
;; 	      '((".*" "~/tmp/" t))))


;; 保存の間隔
(setq auto-save-timeout 10)	 ;; 秒   (デフォルト : 30)
(setq auto-save-interval 100)	 ;; 打鍵 (デフォルト : 300)




;; auto-save-list 自動保存のリスト  (~/.emacs.d/auto-save-list/.saves-xxx)
;; --------------------------------------------------------------------

;; 実行の有無
(setq auto-save-list-file-prefix nil)

;; ;; 格納ディレクトリーの変更
;; (setq auto-save-list-file-prefix "~/tmp/.saves-")



;; lock ロックファイル (.#xxx)
;; -------------------------------------------

;; 実行の有無
(setq create-lockfiles nil)




(defvar my-inhibit-auto-file-directory-list
  (list
   "~/DropBox"
   (concat (getenv "USERPROFILE") "/Google ドライブ")
   )
  "自動作成(バックアップ、自動保存、ロック)を禁止するディレクトリーのリスト")
  
(add-hook 'find-file-hook
	  '(lambda ()
	     (when (listp my-inhibit-auto-file-directory-list)
	       (let ((inhibit-ptn (concat "^\\(" (mapconcat '(lambda(str) (regexp-quote (expand-file-name str)))
							    my-inhibit-auto-file-directory-list "\\|") "\\)")))
		 (when (string-match inhibit-ptn buffer-file-name)
		   (setq backup-inhibited t) ;; バックアップ禁止
		   (auto-save-mode nil)	     ;; 自動保存しない
		   (make-local-variable 'create-lockfiles) ;; ロックファイルを作成しない
		   (setq create-lockfiles nil)
		   )))))


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; 
;; generic
;; 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; 
;; パッケージ
;; 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(require 'package)
(setq package-archives
      (append package-archives '(("melpa" . "http://melpa.milkbox.net/packages/")
				 ("marmalade" . "http://marmalade-repo.org/packages/"))))
(package-initialize)



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; 
;; ロードパスの設定
;; 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(add-to-list 'load-path "~/.emacs.d/site-lisp")

;; ;; load-path に登録されたディレクトリーを subdir 扱い
;; ;;   注:アクセス件でエラーになりやすい
;; (normal-top-level-add-subdirs-to-load-path)



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; 
;; auto-complete
;; 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(when (require 'auto-complete-config nil t)
  (ac-config-default))



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; 
;; プログラミング
;; 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
