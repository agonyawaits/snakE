set path+=$PROJECT_DIR/src/
set path+=$PROJECT_DIR/include/
set path+=$PROJECT_DIR/build/

set makeprg=build.bash
nnoremap <F2> :wall \| make!<cr>
nnoremap <F3> :!run.bash<cr>

packadd termdebug
let g:termdebug_wide=1
hi debugPC term=reverse ctermbg=black guibg=black
nnoremap <F5> :Termdebug snake<cr><c-w>l
nnoremap <F6> :Run<cr>
nnoremap <F7> :Continue<cr>
nnoremap <F8> :Clear<cr>
nnoremap <F9> :Break<cr>
nnoremap <F10> :Over<cr>
nnoremap <F11> :Step<cr>
