//Bibliotecas
#include <windows.h>

//Variáveis

HWND input;
HBRUSH fundo;
char texto[50] = "Enviar";
//Button
HWND button;
HFONT fontebutton;
//HBITMAP imagem;



//Função que controla a janela
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    
	// Quando algum botão ou input é usado
    if (msg == WM_COMMAND) {

        // Se o botão com ID 1 foi clicado
        if (LOWORD(wParam) == 1) {

            // Pega o texto digitado no input e salva na variável "texto"
            GetWindowText(input, texto, 100);

            // Manda a janela redesenhar (para aparecer o texto novo na tela)
            InvalidateRect(hwnd, NULL, TRUE);
        }
    }
	
	if (msg == WM_PAINT) {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

		SetTextColor(hdc, RGB(255, 255, 255)); // muda a cor do texto
    	SetBkMode(hdc, TRANSPARENT);       // deixa o fundo do texto transparente
    	
    	HFONT fonte = CreateFont(50, 0, 0, 0, FW_BOLD, 0, 0, 0, 
		ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, 
		DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Arial"
        );
		SelectObject(hdc, fonte);
        TextOut(hdc, 155, 30, "Login", 5); //escreve algo na tela
        
        //Arrumar(A imagem n vem)
        //if (imagem) {
            //HDC hdcMem = CreateCompatibleDC(hdc);
            //SelectObject(hdcMem, imagem);
           //BitBlt(hdc, 50, 50, 200, 200, hdcMem, 0, 0, SRCCOPY);
            //DeleteDC(hdcMem);
        //}else if (imagem == NULL){
        	//MessageBox(NULL, "Erro ao carregar imagem", "Erro", MB_OK);
		//}
        
        

		DeleteObject(fonte);
        EndPaint(hwnd, &ps);
        return 0;
    }

    if (msg == WM_DESTROY) {
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    WNDCLASS wc;
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "MinhaJanela";
    
    fundo = CreateSolidBrush(RGB(242, 243, 174)); //Vanilla Custard(amarelinho)
	wc.hbrBackground = fundo;

    RegisterClass(&wc);
    
    //Arrumar(A imagem n vem)
   // imagem = (HBITMAP)LoadImage(NULL, "cadeado.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

    HWND hwnd = CreateWindow("MinhaJanela", "Login",
        WS_OVERLAPPEDWINDOW,
        100, 100, 500, 400,
        NULL, NULL, hInstance, NULL);

    ShowWindow(hwnd, nCmdShow);
    
     input = CreateWindow("EDIT", "",
        WS_VISIBLE | WS_CHILD | WS_BORDER,
        140, 100, 170, 25,
        hwnd, NULL, hInstance, NULL);
        
     input = CreateWindow("EDIT", "",
        WS_VISIBLE | WS_CHILD | WS_BORDER,
        140, 135, 170, 25,
        hwnd, NULL, hInstance, NULL);   

	//Button
	fontebutton = CreateFont(20, 0, 0, 0, FW_BOLD, 0, 0, 0, 
	ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, 
	DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Arial"
    );
    button = CreateWindow("BUTTON", "Enviar",
        WS_VISIBLE | WS_CHILD,
        160, 175, 120, 30,
        hwnd, (HMENU)1, hInstance, NULL);
    SendMessage(button, WM_SETFONT, (WPARAM)fontebutton, TRUE);
    

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}
