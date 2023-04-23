section .text
    global firstrule
    global secondrule
    first_rule:
        push ebp
        mov ebp,esp
        push edi
        mov edi,dword[ebp+8];адрес строки
        mov ecx,dword[ebp+12];размер строки
        .cycle:;если заглавная буква - прибавляем 32 к коду буквы (*код заглавной*+32=*код соотв. строчной*)
            cmp dword[edi+4*ecx-4],'A'
            jb .next
            cmp dword[edi+4*ecx-4],'Z'
            ja .next
            add dword[edi+4*ecx-4],32
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
        mov edx,dword[edi]
        push ebx
        mov ebx,1
        .cycle:;в обратном порядке заносим в стек все элементы, не равные первому
            cmp edx,dword[edi+4*ecx-4]
            je .next
            push dword[edi+4*ecx-4]
            inc ebx
            .next:
                loop .cycle
        mov ecx,dword[ebp+12]
        push edx
        .zeros:;обнуляем все значения строки
            mov dword[edi+4*ecx-4],0
            loop .zeros
        mov ecx,ebx
        mov ebx,0
        .ans:;занесение данных из стека в строку
            pop dword[edi+4*ebx]
            inc ebx
            loop .ans
        pop ebx
        pop edi
        leave
        ret