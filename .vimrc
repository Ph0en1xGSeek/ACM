syntax on
set nu
set tabstop=4
set shiftwidth=4
set showmatch
set nocompatible
set ai!
set cindent
if has("autocmd")
  au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif
  set mouse=a
endif
