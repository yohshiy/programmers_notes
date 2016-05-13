
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; 
;; �J�X�^�}�C�Y
;; 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; �J�X�^�}�C�Y�p�̃t�@�C����ݒ�
(setq custom-file "~/.emacs.d/custom_setttings.el")

;; �J�X�^�}�C�Y�p�t�@�C�������[�h
(when (file-exists-p custom-file)
  (load custom-file))


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; �����\���ʒu�A�T�C�Y
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(setq initial-frame-alist
      '((top . 80)			; �ʒu(��)
	(left . 200)			; �ʒu(��)
	(width . 150)			; �T�C�Y(��)
	(height . 50)			; �T�C�Y(����)
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

;; �t�@�C���̕����R�[�h���� BOM �t�� UTF-8
(set-default 'buffer-file-coding-system 'utf-8-with-signature)



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; �L�[�ݒ�
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; Windows �̏ꍇ�A IME �̕ϊ��ŃG���[���łȂ��悤�ɂ���
(when (eq system-type 'windows-nt)
  (global-set-key [M-kanji] 'ignore)
  (global-set-key [kanji] 'ignore)
  )


;; �^�[�~�i���̏ꍇ(window-system �� nil)�A<backspace> �� C-h �ɂȂ邽�߁A
;; C-h �ňꕶ���폜�ɐݒ�
(unless window-system
  (let ((hkey (kbd "C-h")))
    (global-set-key hkey 'delete-backward-char)
    (define-key isearch-mode-map hkey 'isearch-delete-char) ;; �C���N�������^���T�[�`�p
    (add-hook 'c-mode-common-hook
	      '(lambda () (local-set-key hkey 'c-electric-delete))) ;; C ����n���[�h
    ))
(global-set-key (kbd "M-?") 'help-command) ; �w���v�L�[��ύX



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
(setq backup-directory-alist '(("." . "~/.ehist")))


;; �ԍ��t���ɂ�镡���ۑ�
(setq version-control     t)  ;; ���s�̗L��
(setq kept-new-versions   5)  ;; �ŐV�̕ێ���
(setq kept-old-versions   1)  ;; �ŌÂ̕ێ���
(setq delete-old-versions t)  ;; �͈͊O���폜



;; auto-save �����ۑ��t�@�C�� (#xxx#)
;; -------------------------------------------

;; ���s�̗L��
;; (setq auto-save-default nil)

;; �i�[�f�B���N�g���[�̕ύX
;;   (�Ώۃt�@�C���̃p�^�[�� . �ۑ��t�@�C���p�X) �̃��X�g
(setq auto-save-file-name-transforms
      '(("\\`/[^/]*:\\([^/]*/\\)*\\([^/]*\\)\\'" "~/.emacs.d/auto-save-list/\\2" t)))


;; �ۑ��̊Ԋu
(setq auto-save-timeout 10)	 ;; �b   (�f�t�H���g : 30)
(setq auto-save-interval 100)	 ;; �Ō� (�f�t�H���g : 300)




;; auto-save-list �����ۑ��̃��X�g  (~/.emacs.d/auto-save-list/.saves-xxx)
;; --------------------------------------------------------------------

;; ���s�̗L��
(setq auto-save-list-file-prefix nil)

;; �i�[�f�B���N�g���[�̕ύX
;; (setq auto-save-list-file-prefix "~/tmp/.saves-")



;; lock ���b�N�t�@�C�� (.#xxx)
;; -------------------------------------------

;; ���s�̗L��
;; (setq create-lockfiles nil)



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; 
;; �p�b�P�[�W
;; 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(require 'package)
(setq package-archives
      (append package-archives '(("melpa" . "http://melpa.milkbox.net/packages/")
				 ("marmalade" . "http://marmalade-repo.org/packages/"))))
(package-initialize)



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; 
;; ���[�h�p�X�̐ݒ�
;; 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(add-to-list 'load-path "~/.emacs.d/site-lisp")

;; load-path �ɓo�^���ꂽ�f�B���N�g���[�� subdir ����
(normal-top-level-add-subdirs-to-load-path)



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; 
;; ���̑�
;; 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; �x�����֎~
(setq ring-bell-function 'ignore)


;; �X�^�[�g���(���b�Z�[�W)��\�����Ȃ�
(setq inhibit-startup-screen t)

;;; �̈�I�����A�폜�L�[�ňꊇ�폜
(delete-selection-mode t)

