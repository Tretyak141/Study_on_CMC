section .text
    global firstrule
    global secondrule
    firstrule:
        push ebp
        mov ebp,esp
        push edi
        push esi
        mov edi,dword[ebp+8];адрес строки
        mov esi,dword[ebp+12];адрес выходной строки
        mov ecx,dword[ebp+16];размер строки
        .cycle:
            cmp byte[edi+ecx-1],'A'
            jb .next
            cmp byte[edi+ecx-1],'Z'
            ja .next
            mov al,byte[edi+ecx-1]
            add al,32
            mov byte[esi+ecx-1],al
            jmp .all_next
            .next:
                mov al,byte[edi+ecx-1]
                mov byte[esi+ecx-1],al
                .all_next:
                    loop .cycle
        pop esi
        pop edi
        leave
        ret
    secondrule:
        push ebp
        mov ebp,esp
        push edi
        mov edi,dword[ebp+8]
        mov dl,byte[edi]
        push esi
        mov esi,dword[ebp+12]
        mov byte[esi],dl
        push ebx
        mov ebx,1; текущая длина выходного массива
        mov ecx,dword[ebp+16]
        mov ecx,dword[ecx]
        mov eax,1
        dec ecx
        .cycle:
            cmp byte[edi+eax],dl
            je .next
            push ecx
            mov cl,byte[edi+eax]
            mov byte[esi+ebx],cl
            pop ecx
            inc ebx
            .next:
                inc eax
                loop .cycle
        mov eax,dword[ebp+16]
        mov dword[eax],ebx
        pop ebx
        pop esi
        pop edi
        leave
        ret