section .text
    global firstrule
    global secondrule
    firstrule:
        push ebp
        mov ebp,esp
        push edi
        mov edi,dword[ebp+8];адрес строки
        mov ecx,dword[ebp+12];размер строки
        .cycle:;если заглавная буква - прибавляем 32 к коду буквы (*код заглавной*+32=*код соотв. строчной*)
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

    secondrule:
        push ebp
        mov ebp,esp
        push edi
        mov edi,dword[ebp+8]
        mov ecx,dword[ebp+12]
        movzx edx,byte[edi]
        push ebx
        mov ebx,1
        .cycle:;в обратном порядке заносим в стек все элементы, не равные первому
            cmp dl,byte[edi+ecx-1]
            je .next
            movzx eax,byte[edi+ecx-1]
            push eax
            inc ebx
            .next:
                loop .cycle
        mov ecx,dword[ebp+12]
        push edx
        .zeros:;обнуляем все значения строки
            mov byte[edi+ecx-1],0
            loop .zeros
        mov ecx,ebx
        mov ebx,0
        .ans:;занесение данных из стека в строку
            pop eax
            mov byte[edi+ebx],al
            inc ebx
            loop .ans
        pop ebx
        pop edi
        leave
        ret