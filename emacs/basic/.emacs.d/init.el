
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; 
;; �J�X�^�}�C�Y
;; 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; �J�X�^�}�C�Y�p�̃t�@�C����ݒ�
(setq custom-file "~/.emacs.d/custom_setttings.el")

;; �J�X�^�}�C�Y�p�t�@�C�������[�h
(load custom-file t)



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; �����\���ʒu�A�T�C�Y
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(setq initial-frame-alist
      '((left   . 100)			; �ʒu (X)
	(top    .  50)			; �ʒu (Y)
	(width  . 120)			; �T�C�Y(��)
	(height .  40)			; �T�C�Y(����)
	))



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; �X�N���[��
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; �X�N���[�������ۂ̃J�[�\���̈ړ��s��
(setq scroll-conservatively 1)

;; �X�N���[���J�n�̃}�[�W���̍s��
(setq scroll-margin 10)


;; 1 ��ʃX�N���[�����ɏd��������s��
(setq next-screen-context-lines 10)

;; 1 ��ʃX�N���[�����ɃJ�[�\���̉�ʏ�̈ʒu���Ȃ�ׂ��ς��Ȃ�
(setq scroll-preserve-screen-position t)


;; �}�E�X�z�C�[���ɂ��X�N���[�����̍s��
;;   Shift ���Ȃ߁A Ctrl ���߂Ɉړ�
(setq mouse-wheel-scroll-amount
      '(5				; �ʏ�   (�f�t�H���g 5)
	((shift) . 1)			; Shift  (�f�t�H���g 1)
	((control) . 40)		; Ctrl   (�f�t�H���g nil = ����)
	))


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; ���{��̐ݒ�
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; ���ɍ��킹�����{�ꕶ���R�[�h�ɐݒ�
;;  Windows => SJIS
;;  Linux => ���ϐ� LANG ����
(set-language-environment "Japanese")

;; set-language-environment �ł��܂������Ȃ��ꍇ�ɐݒ�
;; (setq prefer-coding-system 'utf-8)

;; �t�@�C���̕����R�[�h�����ʂɎw�肵�����ꍇ�ɐݒ�
;; (setq-default buffer-file-coding-system 'utf-8-with-signature) ; BOM �t�� UTF-8




;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; �L�[�ݒ�
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; Windows �̏ꍇ�A
;; IME �̕ϊ��ŃG���[���ł�̂ŁA�������Ȃ��֐������蓖�Ă�
(when (eq system-type 'windows-nt)
  (global-set-key [M-kanji] 'ignore)
  (global-set-key [kanji] 'ignore)
  )


;; �^�[�~�i���̏ꍇ(window-system �� nil)�A
;; <backspace> �� C-h �ɂȂ�̂ŁA C-h �� <delete> (C-?) �������ꂽ���Ƃɂ���
(unless window-system
  (keyboard-translate ?\C-h ?\C-?))
;; C-h �ȊO���w���v�L�[�Ɋ��蓖��
(global-set-key (kbd "M-?") 'help-command)



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; 
;; �����A�u�����̑啶���A�������̋��
;; 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; �I�v�V������ "Ignore Case for Search" �Őݒ��
;;
;; ;; ����(�S��)
;; (setq case-fold-search t)
;;
;; ;; �C���N�������^���T�[�`
;; (setq isearch-case-fold-search nil)


;; �o�b�t�@�[���̌���
(setq read-buffer-completion-ignore-case t)

;; �t�@�C�����̌���
(setq read-file-name-completion-ignore-case t)


;;;�u��(�S��)
;; (setq case-replace t)

;; dabbrev ���̒u��
(setq dabbrev-case-replace nil)



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; 
;; �����쐬�t�@�C��
;; 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


;; backup �t�@�C���I�[�v�����̃o�b�N�A�b�v (xxx~)
;; -------------------------------------------

;; ���s�̗L��
(setq make-backup-files t)

;; �i�[�f�B���N�g���[�̕ύX
;;   (�Ώۃf�B���N�g���[ . �i�[�f�B���N�g���[) �̃��X�g
(setq backup-directory-alist '((".*" . "~/.ehist")))


;; �ԍ��t���ɂ�镡���ۑ�
(setq version-control     t)  ;; ���s�̗L��
(setq kept-new-versions   5)  ;; �ŐV�̕ێ���
(setq kept-old-versions   1)  ;; �ŌÂ̕ێ���
(setq delete-old-versions t)  ;; �͈͊O���폜



;; auto-save �����ۑ��t�@�C�� (#xxx#)
;; -------------------------------------------

;; ;; ���s�̗L��
;; (setq auto-save-default nil)

;; ;; �i�[�f�B���N�g���[�̕ύX
;; ;;   (�Ώۃt�@�C���̃p�^�[�� . �ۑ��t�@�C���p�X) �̃��X�g
;; (setq auto-save-file-name-transforms
;;       (append auto-save-file-name-transforms
;; 	      '((".*" "~/tmp/" t))))


;; �ۑ��̊Ԋu
(setq auto-save-timeout 10)	 ;; �b   (�f�t�H���g : 30)
(setq auto-save-interval 100)	 ;; �Ō� (�f�t�H���g : 300)




;; auto-save-list �����ۑ��̃��X�g  (~/.emacs.d/auto-save-list/.saves-xxx)
;; --------------------------------------------------------------------

;; ���s�̗L��
(setq auto-save-list-file-prefix nil)

;; ;; �i�[�f�B���N�g���[�̕ύX
;; (setq auto-save-list-file-prefix "~/tmp/.saves-")



;; lock ���b�N�t�@�C�� (.#xxx)
;; -------------------------------------------

;; ���s�̗L��
(setq create-lockfiles nil)




(defvar my-inhibit-auto-file-directory-list
  (list
   "~/DropBox"
   (concat (getenv "USERPROFILE") "/Google �h���C�u")
   )
  "�����쐬(�o�b�N�A�b�v�A�����ۑ��A���b�N)���֎~����f�B���N�g���[�̃��X�g")
  
(add-hook 'find-file-hook
	  '(lambda ()
	     (when (listp my-inhibit-auto-file-directory-list)
	       (let ((inhibit-ptn (concat "^\\(" (mapconcat '(lambda(str) (regexp-quote (expand-file-name str)))
							    my-inhibit-auto-file-directory-list "\\|") "\\)")))
		 (when (string-match inhibit-ptn buffer-file-name)
		   (setq backup-inhibited t) ;; �o�b�N�A�b�v�֎~
		   (auto-save-mode nil)	     ;; �����ۑ����Ȃ�
		   (make-local-variable 'create-lockfiles) ;; ���b�N�t�@�C�����쐬���Ȃ�
		   (setq create-lockfiles nil)
		   )))))


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; 
;; generic
;; 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; 
;; �p�b�P�[�W
;; 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(when (require 'package nil t)
  (setq package-archives
	(append package-archives '(("melpa" . "http://melpa.milkbox.net/packages/")
				   ("marmalade" . "http://marmalade-repo.org/packages/"))))
  (package-initialize))



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; 
;; ���[�h�p�X�̐ݒ�
;; 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(add-to-list 'load-path "~/.emacs.d/site-lisp")

;; ;; load-path �ɓo�^���ꂽ�f�B���N�g���[�� subdir ����
;; ;;   ��:�A�N�Z�X���ŃG���[�ɂȂ�₷��
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
;; �v���O���~���O
;; 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; ����

;; ���[(�����̑O)�ł̓C���f���g�A����ȊO�̓^�u�̑}��
(setq tab-always-indent nil)
(setq c-tab-always-indent nil)

;; �󔒂���x�ɍ폜
(if (fboundp 'global-hungry-delete-mode)
    (global-hungry-delete-mode 1))

;; ���s���ȂǂɎ����ŃC���f���g 
;;   (C-j �� C-m �̓���ւ�)
(if (fboundp 'electric-indent-mode)
    (electric-indent-mode 0))

;; ����̕�������͂���Ǝ����ŉ��s�A�C���f���g
;; (electric-layout-mode 1)


;; C �n����
;; ================================================================

(defun my-all-cc-mode-init ()
  ;; C �n(cc-mode ���p������)���[�h���ʂ̐ݒ���L�q

  ;; �󔒂Ȃǂ���x�ɍ폜
  (c-toggle-hungry-state 1)

  ;; ���s���ȂǂŎ����C���f���g
  ;; (c-toggle-electric-state 1)
  ;; 
  ;; ";", "}" �Ȃǂ���͂����Ƃ��Ɏ������s
  ;; �����C���f���g���ꏏ�� ON �ɂȂ�
  ;; (c-toggle-auto-newline 1)

  )
(add-hook 'c-mode-common-hook 'my-all-cc-mode-init)


;; C, C++
;; ================================================================

;; .h �ł� C++
(add-to-list 'auto-mode-alist '("\\.h\\'" . c++-mode))


(autoload 'vs-set-c-style "vs-set-c-style"
  "Set the current buffer's c-style to Visual Studio like style. ")

(defun my-c-c++-mode-init ()
  ;; C, C++ �p�̐ݒ���L�q
  

  ;; Visual Studio ���̐ݒ�
  ;; (vs-set-c-style)
  )
(add-hook 'c-mode-hook 'my-c-c++-mode-init)
(add-hook 'c++-mode-hook 'my-c-c++-mode-init)


;; C#
;; ================================================================

(defun my-csharp-mode-init ()
  ;; C# �p�̐ݒ���L�q

  
  ;; auto-complete ��L��
  (if (fboundp 'auto-complete-mode)
      (auto-complete-mode 1))

  ;; "{" �̃C���f���g�𐳏��
  (local-set-key "{" 'c-electric-brace)

  ;; �C���f���g����
  (setq c-basic-offset 4)
  (setq tab-width 4)
  (setq c-hanging-braces-alist
	'((defun-open   	before after)
	  (defun-close 	    	before after)
	  (class-open  	    	before after)
	  (class-close 	    	before)
	  (namespace-open   	before after)
	  (namespace-close	before after)
	  (inline-open      	before after)
	  (inline-close     	before after)
	  (block-open   	before after)
	  (block-close  	before after)
	  (statement-case-open after)
	  (substatement-open   before after))))
(add-hook 'csharp-mode-hook 'my-csharp-mode-init)

(add-to-list 'auto-mode-alist '("\\.xaml\\'" . xml-mode))


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; 
;; Tips
;; 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; �r�[�v���֎~
(setq ring-bell-function 'ignore)


;; �X�^�[�g���(���b�Z�[�W)��\�����Ȃ�
(setq inhibit-startup-screen t)


;; �I��̈���폜�L�[�ňꊇ�폜
(delete-selection-mode t)

;; shift + ���L�[�ŗ̈�I��
(if (fboundp 'pc-selection-mode)
    (pc-selection-mode))


;; �s���� kill-line (C-k) �ōs�S�̂ŃJ�b�g
(setq kill-whole-line t)

;; �ǂݎ���p�o�b�t�@�[�ł��J�b�g�n�ŃR�s�[�\
(setq kill-read-only-ok t)


;; ediff ���Ƀt���[�����g��Ȃ�
(setq ediff-window-setup-function 'ediff-setup-windows-plain)


;; png, jpg �Ȃǂ̃t�@�C�����摜�Ƃ��ĕ\��
(setq auto-image-file-mode t)
