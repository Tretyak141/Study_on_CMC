

section .text
    global firstrule
    firstrule:
        push ebp
        mov ebp,esp
        push edi
        mov edi,dword[ebp+8];адрес строки
        mov ecx,dword[ebp+12];размер строки
        .cycle:
            cmp byte[edi+ecx-1],'A'
            jb .next
            cmp byte[edi+ecx-1],'Z'
            ja .next
            add byte[edi+ecx-1],32
            .next:
                loop .cycle
        pop edi
        leave
        ret