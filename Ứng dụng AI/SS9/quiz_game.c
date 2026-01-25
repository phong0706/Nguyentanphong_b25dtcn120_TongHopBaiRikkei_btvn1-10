/*
 * ===================================================================
 * QUIZ GAME - CHUONG TRINH TRO CHOI CAU HOI TRAC NGHIEM
 * ===================================================================
 * 
 * MO TA: Chuong trinh tro choi cau hoi trac nghiem duoc viet bang ngon ngu C
 * 
 * CAC CHUC NANG CHINH:
 * 1. Ngan hang cau hoi: Luu tru 10 cau hoi trac nghiem voi 4 lua chon
 * 2. Choi game: Chon ngau nhien 10 cau tu ngan hang de choi
 * 3. Tinh diem: Moi cau dung duoc +1 diem
 * 4. Bang xep hang: Luu va hien thi ket qua (sap xep theo diem giam dan)
 * 5. Giao dien dep: Co mau sac, animation, box drawing
 * 
 * KHAI NIEM CAN BIET:
 * - STRUCT: Kieu du lieu tu dinh nghia, gom nhieu bien thanh mot nhom
 * - FILE I/O: Doc/ghi du lieu tu file de luu tru lau dai
 * - RANDOM: Tao so ngau nhien de chon cau hoi
 * - ARRAY: Mang de luu tru nhieu phan tu cung kieu
 * - FUNCTION: Ham de chia code thanh cac phan nho, de quan ly
 * 
 * ===================================================================
 */

/* ========== CAC THU VIEN CAN THIET ========== */

// stdio.h: Thu vien chua cac ham nhap/xuat (printf, scanf, FILE, fopen, fclose, fprintf, fscanf)
//          - printf: In ra man hinh
//          - scanf: Doc tu ban phim
//          - FILE: Kieu du lieu de lam viec voi file
//          - fopen: Mo file de doc/ghi
//          - fclose: Dong file
//          - fprintf: Ghi vao file
//          - fscanf: Doc tu file
#include <stdio.h>

// stdlib.h: Thu vien chua cac ham tien ich (rand, srand, qsort, system)
//           - rand: Tao so ngau nhien
//           - srand: Khoi tao seed cho rand (de moi lan chay co so khac nhau)
//           - qsort: Sap xep mang (quick sort)
//           - system: Chay lenh he thong (vi du: cls, clear)
#include <stdlib.h>

// string.h: Thu vien chua cac ham xu ly chuoi (strcpy, strcspn, strlen, strchr)
//            - strcpy: Copy chuoi
//            - strcspn: Tim vi tri ky tu trong chuoi
//            - strlen: Do dai chuoi
//            - strchr: Tim ky tu trong chuoi
#include <string.h>

// time.h: Thu vien chua ham lay thoi gian hien tai
//         - time: Lay thoi gian hien tai (dung lam seed cho srand)
#include <time.h>

// ctype.h: Thu vien chua cac ham xu ly ky tu (toupper)
//          - toupper: Chuyen chu thuong thanh chu hoa
#include <ctype.h>

// Windows.h (chi cho Windows): Thu vien chua cac ham dac biet cua Windows
//                               - SetConsoleOutputCP: Set ma hoa cho output
//                               - SetConsoleCP: Set ma hoa cho input
//                               - Sleep: Delay (nghi) trong mot khoang thoi gian
#ifdef _WIN32
#include <windows.h>
#else
// unistd.h (cho Linux/macOS): Thu vien chua ham usleep (delay)
#include <unistd.h>
#endif

/* ========== DINH NGHIA HANG SO (CONSTANTS) ========== */
/*
 * GIAI THICH: #define la lenh dinh nghia hang so (constant)
 *             Khi bien dich, moi noi co MAX_QUESTIONS se duoc thay the bang 10
 *             Uu diem: De sua doi, khong phai tim tung cho trong code
 */
#define MAX_QUESTIONS 10        // So luong cau hoi toi da trong ngan hang
#define QUESTIONS_TO_PLAY 10    // So cau hoi se duoc choi (random 10 cau)
#define MAX_NAME_LENGTH 50      // Do dai toi da cua ten nguoi choi (49 ky tu + 1 ky tu '\0')
#define MAX_QUESTION_LENGTH 200 // Do dai toi da cua cau hoi
#define MAX_CHOICE_LENGTH 100   // Do dai toi da cua moi lua chon (A, B, C, D)
#define MAX_LEADERBOARD 100     // So nguoi choi toi da trong bang xep hang
#define LEADERBOARD_FILE "leaderboard.txt"  // Ten file luu bang xep hang

/* ========== DINH NGHIA STRUCT (CAU TRUC DU LIEU) ========== */
/*
 * GIAI THICH STRUCT:
 * - Struct la kieu du lieu tu dinh nghia, gom nhieu bien thanh mot nhom
 * - typedef struct: Dinh nghia ten moi cho struct (de dung nhu kieu du lieu)
 * - Vi du: Question q;  // q la bien kieu Question
 * 
 * TAI SAO DUNG STRUCT?
 * - Gom nhom cac thong tin lien quan voi nhau
 * - De quan ly va truyen tham so cho ham
 * - Giong nhu mot "object" trong OOP (nhung don gian hon)
 */

// Cau truc luu tru cau hoi (Question)
// Moi cau hoi gom: noi dung cau hoi, 4 lua chon, dap an dung
typedef struct {
    char question[MAX_QUESTION_LENGTH];      // Noi dung cau hoi (vi du: "Thu do cua Viet Nam la gi?")
    char choices[4][MAX_CHOICE_LENGTH];      // 4 lua chon A, B, C, D (mang 2 chieu: 4 dong, moi dong MAX_CHOICE_LENGTH ky tu)
    char correctAnswer;                       // Dap an dung ('A', 'B', 'C', hoac 'D')
} Question;

// Cau truc luu tru nguoi choi (Player)
// Moi nguoi choi gom: ten va diem so
typedef struct {
    char name[MAX_NAME_LENGTH];  // Ten nguoi choi (mang ky tu)
    int score;                    // Diem so (so nguyen)
} Player;

/* ========== CAC HAM TIEN ICH (UTILITY FUNCTIONS) ========== */
/*
 * GIAI THICH HAM (FUNCTION):
 * - Ham la mot khoi code co the goi nhieu lan
 * - void: Ham khong tra ve gia tri
 * - int: Ham tra ve so nguyen
 * - Tham so: Du lieu truyen vao ham (trong dau ngoac)
 * - return: Tra ve ket qua (neu ham co kieu tra ve)
 */

/**
 * Khoi tao console de hien thi UTF-8 (chi cho Windows)
 * 
 * GIAI THICH:
 * - UTF-8: Ma hoa ky tu de hien thi tieng Viet co dau
 * - 65001: Ma UTF-8 trong Windows
 * - #ifdef _WIN32: Chi chay code nay neu la Windows
 * 
 * TAI SAO CAN?
 * - Mac dinh Windows console khong hien thi tieng Viet dung
 * - Ham nay set ma hoa UTF-8 de hien thi tieng Viet co dau
 */
void setupConsole() {
    #ifdef _WIN32
    SetConsoleOutputCP(65001);  // Set UTF-8 cho output (in ra man hinh)
    SetConsoleCP(65001);        // Set UTF-8 cho input (nhap tu ban phim)
    #endif
}

/**
 * Khoi tao seed cho ham random
 * 
 * GIAI THICH:
 * - rand(): Ham tao so ngau nhien (nhung thuc ra la "gia ngau nhien" - pseudo random)
 * - srand(): Khoi tao seed (hat giong) cho rand()
 * - time(NULL): Lay thoi gian hien tai (so giay tu 1/1/1970)
 * 
 * TAI SAO CAN?
 * - Neu khong co srand(), moi lan chay se co cung day so ngau nhien
 * - Dung time(NULL) lam seed de moi lan chay co so khac nhau
 * - (unsigned int): Ep kieu (cast) tu time_t sang unsigned int
 * 
 * VI DU:
 * - Lan 1: srand(1234567890) -> rand() tra ve: 5, 8, 2, ...
 * - Lan 2: srand(1234567891) -> rand() tra ve: 3, 9, 1, ... (khac nhau!)
 */
void initializeRandom() {
    srand((unsigned int)time(NULL));  // Khoi tao seed bang thoi gian hien tai
}

/**
 * Kiem tra dap an co hop le khong (A, B, C, hoac D)
 * 
 * THAM SO:
 *   - answer: Ky tu dap an nguoi choi nhap (co the la chu thuong hoac chu hoa)
 * 
 * GIAI THICH:
 * - toupper(): Chuyen chu thuong thanh chu hoa (vi du: 'a' -> 'A')
 * - (char): Ep kieu tu int (toupper tra ve int) sang char
 * - ||: Toan tu OR (hoac) - neu mot trong cac dieu kien dung thi tra ve 1
 * - return: Tra ve 1 neu hop le, 0 neu khong hop le
 * 
 * VI DU:
 * - isValidAnswer('a') -> chuyen thanh 'A' -> return 1 (dung)
 * - isValidAnswer('B') -> giu nguyen 'B' -> return 1 (dung)
 * - isValidAnswer('x') -> chuyen thanh 'X' -> return 0 (sai)
 */
int isValidAnswer(char answer) {
    answer = (char)toupper(answer);  // Chuyen chu thuong thanh chu hoa
    return (answer == 'A' || answer == 'B' || answer == 'C' || answer == 'D');  // Kiem tra co phai A, B, C, hoac D khong
}

/**
 * Chuyen dap an sang chu hoa va kiem tra hop le
 * 
 * THAM SO:
 *   - answer: Con tro (pointer) den bien char
 * 
 * GIAI THICH CON TRO (POINTER):
 * - Con tro la bien luu dia chi cua bien khac
 * - char *answer: Con tro den bien kieu char
 * - *answer: Lay GIA TRI cua bien ma con tro tro toi
 * - &answer: Lay DIA CHI cua bien
 * 
 * TAI SAO DUNG CON TRO?
 * - De thay doi gia tri cua bien trong ham (pass by reference)
 * - Neu khong dung con tro, thay doi trong ham khong anh huong bien ben ngoai
 * 
 * VI DU:
 *   char c = 'a';
 *   normalizeAnswer(&c);  // Truyen dia chi cua c
 *   // Sau khi goi ham, c se thanh 'A'
 */
int normalizeAnswer(char *answer) {
    *answer = (char)toupper(*answer);  // Chuyen chu thuong thanh chu hoa (thay doi gia tri qua con tro)
    return isValidAnswer(*answer);     // Kiem tra hop le
}

/**
 * Loai bo khoang trang o dau va cuoi chuoi
 * 
 * THAM SO:
 *   - str: Con tro den chuoi can xu ly
 * 
 * GIAI THICH:
 * - NULL: Gia tri rong (khong tro den dau ca)
 * - strlen(): Ham do dai chuoi (so ky tu, khong tinh '\0')
 * - '\0': Ky tu ket thuc chuoi (null terminator)
 * - '\t': Ky tu tab
 * - '\n': Ky tu xuong dong (newline)
 * - '\r': Ky tu ve dau dong (carriage return)
 * 
 * THUAT TOAN:
 * 1. Tim vi tri bat dau (bo qua khoang trang o dau)
 * 2. Tim vi tri ket thuc (bo qua khoang trang o cuoi)
 * 3. Di chuyen phan chuoi hop le ve dau
 * 
 * VI DU:
 *   Input:  "  Hello World  "
 *   Output: "Hello World"
 */
void trimString(char *str) {
    // Kiem tra neu chuoi rong hoac NULL
    if (str == NULL || strlen(str) == 0) {
        return;  // Thoat ngay neu khong co gi de xu ly
    }
    
    int start = 0;              // Vi tri bat dau chuoi hop le
    int len = strlen(str);       // Do dai chuoi
    int end = len - 1;           // Vi tri ket thuc chuoi hop le (chi so cuoi cung)
    
    // Buoc 1: Loai bo khoang trang o DAU chuoi
    // Duyet tu dau den cuoi, tim vi tri dau tien KHONG phai khoang trang
    while (start < len && (str[start] == ' ' || str[start] == '\t' || str[start] == '\n' || str[start] == '\r')) {
        start++;  // Tang start len cho den khi gap ky tu khong phai khoang trang
    }
    
    // Neu toan bo la khoang trang
    if (start >= len) {
        str[0] = '\0';  // Dat chuoi thanh rong
        return;
    }
    
    // Buoc 2: Loai bo khoang trang o CUOI chuoi
    // Duyet tu cuoi len dau, tim vi tri cuoi cung KHONG phai khoang trang
    while (end >= start && (str[end] == ' ' || str[end] == '\t' || str[end] == '\n' || str[end] == '\r')) {
        end--;  // Giam end xuong cho den khi gap ky tu khong phai khoang trang
    }
    
    // Buoc 3: Di chuyen phan chuoi hop le ve dau
    // Copy tu vi tri start den end ve vi tri 0
    int i;
    for (i = 0; i <= end - start; i++) {
        str[i] = str[start + i];  // Copy tung ky tu
    }
    str[i] = '\0';  // Dat ky tu ket thuc chuoi
}

/**
 * Kiem tra ten nguoi choi co hop le khong
 */
int isValidName(const char *name) {
    if (name == NULL || strlen(name) == 0) {
        return 0;
    }
    
    if (strlen(name) > MAX_NAME_LENGTH - 1) {
        return 0;
    }
    
    int hasValidChar = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] != ' ' && name[i] != '\t' && name[i] != '\n') {
            hasValidChar = 1;
            break;
        }
    }
    
    if (!hasValidChar) {
        return 0;
    }
    
    const char* invalidChars = "/\\:*?\"<>|";
    for (int i = 0; name[i] != '\0'; i++) {
        if (strchr(invalidChars, name[i]) != NULL) {
            return 0;
        }
    }
    
    return 1;
}

// ========== CAC HAM GIAO DIEN DEP ==========

// ANSI Color Codes (cho terminal hien thi mau)
#define COLOR_RESET   "\033[0m"
#define COLOR_BLACK   "\033[30m"
#define COLOR_RED     "\033[31m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_BLUE    "\033[34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN    "\033[36m"
#define COLOR_WHITE   "\033[37m"
#define COLOR_BOLD    "\033[1m"
#define COLOR_BG_BLUE "\033[44m"
#define COLOR_BG_GREEN "\033[42m"
#define COLOR_BG_RED  "\033[41m"

// Box drawing characters - dung ASCII
#define BOX_TL "+"  // +
#define BOX_TR "+"  // +
#define BOX_BL "+"  // +
#define BOX_BR "+"  // +
#define BOX_H  "-"  // -
#define BOX_V  "|"  // |
#define BOX_C  "+"  // +

/**
 * Xoa man hinh voi hieu ung
 */
void clearScreen() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

/**
 * Delay (sleep) de tao hieu ung
 */
void delay(int milliseconds) {
    #ifdef _WIN32
    Sleep(milliseconds);
    #else
    usleep(milliseconds * 1000);
    #endif
}

/**
 * Hien thi text voi hieu ung typing
 */
void printTyping(const char* text, int speed) {
    for (int i = 0; text[i] != '\0'; i++) {
        printf("%c", text[i]);
        fflush(stdout);
        delay(speed);
    }
}

/**
 * Ve box dep voi border
 */
void printBox(const char* title, int width) {
    printf("\n");
    // Top border
    printf(COLOR_CYAN "%s", BOX_TL);
    for (int i = 0; i < width - 2; i++) printf(BOX_H);
    printf("%s" COLOR_RESET "\n", BOX_TR);
    
    // Title line
    if (title != NULL && strlen(title) > 0) {
        // Loai bo color codes de tinh do dai thuc
        int titleLen = 0;
        int inCode = 0;
        for (int i = 0; title[i] != '\0'; i++) {
            if (title[i] == '\033') inCode = 1;
            else if (inCode && title[i] == 'm') inCode = 0;
            else if (!inCode) titleLen++;
        }
        
        int padding = (width - titleLen - 4) / 2;
        if (padding < 0) padding = 0;
        
        printf(COLOR_CYAN "%s" COLOR_RESET, BOX_V);
        for (int i = 0; i < padding; i++) printf(" ");
        printf("%s", title);
        int remaining = width - titleLen - padding - 4;
        for (int i = 0; i < remaining; i++) printf(" ");
        printf(COLOR_CYAN "%s" COLOR_RESET "\n", BOX_V);
        
        // Separator
        printf(COLOR_CYAN "%s", BOX_V);
        for (int i = 0; i < width - 2; i++) printf(BOX_H);
        printf("%s" COLOR_RESET "\n", BOX_V);
    }
}

/**
 * Ve duong ke ngang dep - dung ky tu ASCII
 */
void printSeparator(int length) {
    printf(COLOR_CYAN);
    for (int i = 0; i < length; i++) {
        printf("=");
    }
    printf(COLOR_RESET "\n");
}

/**
 * Hien thi loading animation dep hon
 */
void showLoading(const char* message, int duration) {
    printf(COLOR_BOLD COLOR_CYAN "%s" COLOR_RESET, message);
    fflush(stdout);
    
    // Animation loading dep hon
    const char* spinner = "|/-\\";
    for (int i = 0; i < 12; i++) {
        printf("\b%c", spinner[i % 4]);
        fflush(stdout);
        delay(duration / 12);
    }
    printf("\b ");  // Xoa ky tu cuoi
    printf(COLOR_BOLD COLOR_GREEN " [OK]" COLOR_RESET "\n");
}

/**
 * Hien thi progress bar dep hon voi animation - dung ky tu ASCII
 */
void showProgressBar(int current, int total, int width) {
    float percentage = (float)current / total;
    int filled = (int)(percentage * width);
    
    printf(COLOR_BOLD COLOR_CYAN "[" COLOR_RESET);
    for (int i = 0; i < width; i++) {
        if (i < filled) {
            // Gradient effect: xanh la dam -> xanh la nhat
            if (i < filled * 0.3) {
                printf(COLOR_BOLD COLOR_GREEN "#" COLOR_RESET);
            } else if (i < filled * 0.7) {
                printf(COLOR_GREEN "=" COLOR_RESET);
            } else {
                printf(COLOR_BOLD COLOR_CYAN "=" COLOR_RESET);
            }
        } else {
            printf(COLOR_WHITE "." COLOR_RESET);
        }
    }
    printf(COLOR_BOLD COLOR_CYAN "] " COLOR_RESET);
    printf(COLOR_BOLD COLOR_YELLOW "%d%%" COLOR_RESET, (int)(percentage * 100));
}

/**
 * Hien thi sparkle effect (hieu ung sao) - dung ky tu ASCII
 */
void showSparkles(int count) {
    const char* sparkles[] = {"*", "*", "*", "*", "*"};
    for (int i = 0; i < count; i++) {
        printf("%s ", sparkles[i % 5]);
        fflush(stdout);
        delay(50);
    }
}

/**
 * Hien thi box dep voi shadow effect - dung ky tu ASCII
 */
void printFancyBox(const char* title, int width) {
    printf("\n");
    
    // Top border with gradient - dung ASCII
    printf(COLOR_BOLD COLOR_MAGENTA "  +" COLOR_RESET);
    for (int i = 0; i < width - 2; i++) {
        if (i < (width - 2) / 3) {
            printf(COLOR_MAGENTA "-" COLOR_RESET);
        } else if (i < 2 * (width - 2) / 3) {
            printf(COLOR_CYAN "-" COLOR_RESET);
        } else {
            printf(COLOR_BLUE "-" COLOR_RESET);
        }
    }
    printf(COLOR_BOLD COLOR_MAGENTA "+" COLOR_RESET "\n");
    
    // Title line
    if (title != NULL && strlen(title) > 0) {
        int titleLen = 0;
        int inCode = 0;
        for (int i = 0; title[i] != '\0'; i++) {
            if (title[i] == '\033') inCode = 1;
            else if (inCode && title[i] == 'm') inCode = 0;
            else if (!inCode) titleLen++;
        }
        
        int padding = (width - titleLen - 4) / 2;
        if (padding < 0) padding = 0;
        
        printf(COLOR_BOLD COLOR_MAGENTA "  |" COLOR_RESET);
        for (int i = 0; i < padding; i++) printf(" ");
        printf("%s", title);
        int remaining = width - titleLen - padding - 4;
        for (int i = 0; i < remaining; i++) printf(" ");
        printf(COLOR_BOLD COLOR_MAGENTA "|" COLOR_RESET "\n");
        
        // Separator
        printf(COLOR_BOLD COLOR_MAGENTA "  +" COLOR_RESET);
        for (int i = 0; i < width - 2; i++) printf(COLOR_CYAN "-" COLOR_RESET);
        printf(COLOR_BOLD COLOR_MAGENTA "+" COLOR_RESET "\n");
    }
}

/**
 * Hien thi ASCII art title dep voi animation - dung ky tu ASCII
 */
void printAsciiTitle() {
    printf("\n\n");
    
    // Simple ASCII title
    const char* lines[] = {
        "  _   _  _   _  _____     _____  __  __  _____  __  __ ",
        " | | | || | | ||  _  \\   /  ___||  \\/  ||  _  ||  \\/  |",
        " | | | || | | || |_| |   | |    | |\\/| || |_| || |\\/| |",
        " | | | || | | ||  _  /   | |    | |  | ||  _  || |  | |",
        " | |_| || |_| || | \\ \\   | |___ | |  | || |_| || |  | |",
        "  \\___/  \\___/ |_|  \\_\\   \\____||_|  |_||_____||_|  |_|"
    };
    
    const char* colors[] = {COLOR_BOLD COLOR_MAGENTA, COLOR_BOLD COLOR_CYAN, COLOR_BOLD COLOR_BLUE, 
                           COLOR_BOLD COLOR_GREEN, COLOR_BOLD COLOR_YELLOW, COLOR_BOLD COLOR_MAGENTA};
    
    for (int i = 0; i < 6; i++) {
        printf("%s%s" COLOR_RESET "\n", colors[i], lines[i]);
        delay(80);
    }
    
    printf("\n");
    printf(COLOR_BOLD COLOR_CYAN);
    printf("                    ===================================\n");
    printf("                     TRO CHOI CAU HOI TRAC NGHIEM\n");
    printf("                    ===================================\n" COLOR_RESET);
    
    // Sparkle effect
    printf(COLOR_BOLD COLOR_YELLOW "                  ");
    showSparkles(5);
    printf(COLOR_RESET "\n\n");
}

/**
 * Hien thi text voi mau sac
 */
void printColored(const char* text, const char* color) {
    printf("%s%s%s", color, text, COLOR_RESET);
}

/**
 * Hien thi cau hoi voi hieu ung dep
 */
void printQuestionBox(const char* question, int qNum, int total, int score) {
    clearScreen();
    
    // Header box
    printBox(NULL, 60);
    printf(COLOR_CYAN "%s" COLOR_RESET " ", BOX_V);
    printf(COLOR_BOLD COLOR_MAGENTA "  CAU HOI %d/%d" COLOR_RESET, qNum, total);
    if (score >= 0) {
        printf(COLOR_CYAN "  |  " COLOR_RESET);
        printf(COLOR_GREEN "Diem: %d/%d" COLOR_RESET, score, qNum - 1);
    }
    printf("\n");
    printSeparator(58);
    
    // Question box
    printf(COLOR_CYAN "%s" COLOR_RESET "\n", BOX_V);
    printf(COLOR_CYAN "%s" COLOR_RESET "  ", BOX_V);
    printf(COLOR_BOLD COLOR_WHITE "%s" COLOR_RESET "\n", question);
    printf(COLOR_CYAN "%s" COLOR_RESET "\n", BOX_V);
}

/**
 * Hien thi lua chon dep
 */
void printChoice(char letter, const char* text, int isHighlight) {
    const char* color = isHighlight ? COLOR_BOLD COLOR_GREEN : COLOR_WHITE;
    printf(COLOR_CYAN "%s" COLOR_RESET "  ", BOX_V);
    printf(COLOR_BOLD COLOR_YELLOW "[%c]" COLOR_RESET "  ", letter);
    printf("%s%s%s\n", color, text, COLOR_RESET);
}

/**
 * Hien thi ket qua dep (dung/sai)
 */
void printResult(int isCorrect, char correctAnswer) {
    printf("\n");
    if (isCorrect) {
        // Hien thi ket qua dung voi animation dep - dung ASCII
        printf(COLOR_BOLD COLOR_GREEN);
        printf("  +=======================================================+\n");
        printf("  |" COLOR_RESET);
        printf(COLOR_BOLD COLOR_GREEN "              [CHINH XAC!]" COLOR_RESET);
        printf(COLOR_BOLD COLOR_GREEN "              |\n");
        printf("  +=======================================================+\n");
        printf("  |" COLOR_RESET);
        printf(COLOR_BOLD COLOR_GREEN "  * Ban nhan duoc +1 diem! *" COLOR_RESET);
        printf(COLOR_BOLD COLOR_GREEN "                        |\n");
        printf("  +=======================================================+\n" COLOR_RESET);
    } else {
        // Hien thi ket qua sai voi animation dep - dung ASCII
        printf(COLOR_BOLD COLOR_RED);
        printf("  +=======================================================+\n");
        printf("  |" COLOR_RESET);
        printf(COLOR_BOLD COLOR_RED "                [SAI ROI!]" COLOR_RESET);
        printf(COLOR_BOLD COLOR_RED "                |\n");
        printf("  +=======================================================+\n");
        printf("  |" COLOR_RESET);
        printf(COLOR_RED "  Dap an dung la: " COLOR_BOLD COLOR_YELLOW "%c" COLOR_RESET, correctAnswer);
        printf(COLOR_BOLD COLOR_RED "                                |\n");
        printf("  +=======================================================+\n" COLOR_RESET);
    }
    delay(1000);
}

// ========== CAC HAM QUAN LY CAU HOI ==========

/**
 * Khoi tao ngan hang cau hoi
 */
void initializeQuestions(Question questions[]) {
    // Cau hoi 1
    strcpy(questions[0].question, "Thu do cua Viet Nam la gi?");
    strcpy(questions[0].choices[0], "Ho Chi Minh");
    strcpy(questions[0].choices[1], "Ha Noi");
    strcpy(questions[0].choices[2], "Da Nang");
    strcpy(questions[0].choices[3], "Hue");
    questions[0].correctAnswer = 'B';
    
    // Cau hoi 2
    strcpy(questions[1].question, "Ngon ngu lap trinh C duoc phat trien vao nam nao?");
    strcpy(questions[1].choices[0], "1969");
    strcpy(questions[1].choices[1], "1972");
    strcpy(questions[1].choices[2], "1975");
    strcpy(questions[1].choices[3], "1980");
    questions[1].correctAnswer = 'B';
    
    // Cau hoi 3
    strcpy(questions[2].question, "Ham nao trong C dung de cap phat bo nho dong?");
    strcpy(questions[2].choices[0], "malloc()");
    strcpy(questions[2].choices[1], "calloc()");
    strcpy(questions[2].choices[2], "realloc()");
    strcpy(questions[2].choices[3], "Tat ca cac dap an tren");
    questions[2].correctAnswer = 'D';
    
    // Cau hoi 4
    strcpy(questions[3].question, "So nguyen to nho nhat la so nao?");
    strcpy(questions[3].choices[0], "0");
    strcpy(questions[3].choices[1], "1");
    strcpy(questions[3].choices[2], "2");
    strcpy(questions[3].choices[3], "3");
    questions[3].correctAnswer = 'C';
    
    // Cau hoi 5
    strcpy(questions[4].question, "Trong C, kieu du lieu nao dung de luu ky tu?");
    strcpy(questions[4].choices[0], "int");
    strcpy(questions[4].choices[1], "char");
    strcpy(questions[4].choices[2], "float");
    strcpy(questions[4].choices[3], "double");
    questions[4].correctAnswer = 'B';
    
    // Cau hoi 6
    strcpy(questions[5].question, "Ham printf() nam trong thu vien nao?");
    strcpy(questions[5].choices[0], "stdlib.h");
    strcpy(questions[5].choices[1], "stdio.h");
    strcpy(questions[5].choices[2], "string.h");
    strcpy(questions[5].choices[3], "math.h");
    questions[5].correctAnswer = 'B';
    
    // Cau hoi 7
    strcpy(questions[6].question, "Con tro NULL trong C co gia tri la gi?");
    strcpy(questions[6].choices[0], "0");
    strcpy(questions[6].choices[1], "1");
    strcpy(questions[6].choices[2], "-1");
    strcpy(questions[6].choices[3], "Khong xac dinh");
    questions[6].correctAnswer = 'A';
    
    // Cau hoi 8
    strcpy(questions[7].question, "Ham nao dung de so sanh hai chuoi trong C?");
    strcpy(questions[7].choices[0], "strcmp()");
    strcpy(questions[7].choices[1], "strcpy()");
    strcpy(questions[7].choices[2], "strlen()");
    strcpy(questions[7].choices[3], "strcat()");
    questions[7].correctAnswer = 'A';
    
    // Cau hoi 9
    strcpy(questions[8].question, "Kich thuoc cua kieu int trong C thuong la bao nhieu byte?");
    strcpy(questions[8].choices[0], "2");
    strcpy(questions[8].choices[1], "4");
    strcpy(questions[8].choices[2], "8");
    strcpy(questions[8].choices[3], "Tuy he thong");
    questions[8].correctAnswer = 'D';
    
    // Cau hoi 10
    strcpy(questions[9].question, "Vong lap nao trong C thuc thi it nhat mot lan?");
    strcpy(questions[9].choices[0], "for");
    strcpy(questions[9].choices[1], "while");
    strcpy(questions[9].choices[2], "do-while");
    strcpy(questions[9].choices[3], "Khong co");
    questions[9].correctAnswer = 'C';
}

/**
 * Tron mang de chon ngau nhien cau hoi (Fisher-Yates Shuffle Algorithm)
 * 
 * THAM SO:
 *   - arr[]: Mang can tron
 *   - n: So phan tu trong mang
 * 
 * GIAI THICH THUAT TOAN FISHER-YATES:
 * - Thuat toan tron mang ngau nhien, dam bao moi hoan vi deu co xac suat bang nhau
 * - Cach hoat dong:
 *   1. Bat dau tu cuoi mang (i = n-1)
 *   2. Chon ngau nhien mot vi tri j tu 0 den i
 *   3. Doi cho phan tu o vi tri i va j
 *   4. Giam i xuong 1 va lap lai
 * 
 * VI DU:
 *   Mang ban dau: [0, 1, 2, 3, 4]
 *   Sau khi tron: [3, 0, 4, 1, 2] (vi du)
 * 
 * TAI SAO DUNG?
 * - De dam bao cau hoi duoc chon ngau nhien, khong bi lap lai
 * - Moi lan choi se co thu tu cau hoi khac nhau
 */
void shuffleArray(int arr[], int n) {
    // Duyet tu cuoi mang len dau
    for (int i = n - 1; i > 0; i--) {
        // Chon ngau nhien mot vi tri j tu 0 den i
        int j = rand() % (i + 1);  // rand() % (i+1) tra ve so tu 0 den i
        
        // Doi cho phan tu o vi tri i va j (swap)
        int temp = arr[i];    // Luu gia tri arr[i] vao bien tam
        arr[i] = arr[j];      // Gan arr[j] vao arr[i]
        arr[j] = temp;        // Gan gia tri tam vao arr[j]
    }
}

/**
 * Chon ngau nhien 5 cau hoi tu 10 cau
 */
void selectRandomQuestions(int selectedIndices[], int totalQuestions, int questionsToSelect) {
    int allIndices[MAX_QUESTIONS];
    
    for (int i = 0; i < totalQuestions; i++) {
        allIndices[i] = i;
    }
    
    shuffleArray(allIndices, totalQuestions);
    
    for (int i = 0; i < questionsToSelect; i++) {
        selectedIndices[i] = allIndices[i];
    }
}

/**
 * Hien thi cau hoi va cac lua chon (cai tien giao dien)
 */
void displayQuestion(Question q, int questionNumber, int totalQuestions, int currentScore) {
    // Hien thi cau hoi voi hieu ung dep
    printQuestionBox(q.question, questionNumber, totalQuestions, currentScore);
    
    // Hien thi cac lua chon voi animation
    printf(COLOR_CYAN "%s" COLOR_RESET "\n", BOX_V);
    delay(100);
    printChoice('A', q.choices[0], 0);
    delay(50);
    printChoice('B', q.choices[1], 0);
    delay(50);
    printChoice('C', q.choices[2], 0);
    delay(50);
    printChoice('D', q.choices[3], 0);
    delay(50);
    
    // Bottom border
    printf(COLOR_CYAN "%s", BOX_BL);
    for (int i = 0; i < 58; i++) printf(BOX_H);
    printf("%s" COLOR_RESET "\n", BOX_BR);
    
    // Prompt
    printf("\n");
    printf(COLOR_BOLD COLOR_YELLOW ">>> " COLOR_RESET);
    printf(COLOR_WHITE "Nhap dap an cua ban " COLOR_RESET);
    printf(COLOR_BOLD COLOR_CYAN "(A/B/C/D)" COLOR_RESET);
    printf(COLOR_WHITE ": " COLOR_RESET);
}

/**
 * Xu ly mot cau hoi: hien thi, nhan dap an, kiem tra
 * 
 * THAM SO:
 *   - question: Cau hoi can hien thi (kieu Question)
 *   - questionNumber: So thu tu cau hoi (1, 2, 3, ...)
 *   - totalQuestions: Tong so cau hoi
 *   - currentScore: Diem hien tai
 * 
 * GIAI THICH:
 * - Ham nay xu ly toan bo qua trinh: hien thi cau hoi, nhan dap an, kiem tra
 * - Do-while loop: Lap lai cho den khi nguoi choi nhap dung
 * - fgets(): Doc toan bo dong (khac scanf chi doc den khoang trang)
 * - Validation: Kiem tra chat che de tranh loi nhap
 * 
 * RETURN:
 *   - 1: Dap an dung
 *   - 0: Dap an sai
 */
int processQuestion(Question question, int questionNumber, int totalQuestions, int currentScore) {
    char answer;              // Dap an nguoi choi nhap
    char input[100];          // Buffer de doc toan bo dong nhap vao
    int validInput = 0;       // Co hieu: 1 = hop le, 0 = khong hop le
    
    // Buoc 1: Hien thi cau hoi
    displayQuestion(question, questionNumber, totalQuestions, currentScore);
    
    // Buoc 2: Nhan dap an (lap lai cho den khi hop le)
    do {
        // Doc toan bo dong input (fgets doc ca khoang trang, khac scanf)
        // stdin: Standard input (ban phim)
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Loi khi nhap! Vui long thu lai: ");
            continue;  // Quay lai dau vong lap
        }
        
        // Loai bo ky tu xuong dong '\n' o cuoi chuoi
        int len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';  // Thay '\n' bang '\0' (ket thuc chuoi)
            len--;                   // Giam do dai
        }
        
        // VALIDATION 1: Kiem tra dong rong (chi nhap Enter)
        if (len == 0) {
            printf("Khong duoc de trong! Vui long nhap A, B, C hoac D: ");
            continue;
        }
        
        // VALIDATION 2: Kiem tra chi co khoang trang
        int onlySpaces = 1;  // Gia dinh chi co khoang trang
        for (int i = 0; i < len; i++) {
            if (input[i] != ' ' && input[i] != '\t') {
                onlySpaces = 0;  // Tim thay ky tu khong phai khoang trang
                break;
            }
        }
        
        if (onlySpaces) {
            printf("Khong duoc nhap khoang trang! Vui long nhap A, B, C hoac D: ");
            continue;
        }
        
        // VALIDATION 3: Lay ky tu dau tien (bo qua khoang trang o dau)
        int startIdx = 0;
        while (startIdx < len && (input[startIdx] == ' ' || input[startIdx] == '\t')) {
            startIdx++;  // Bo qua khoang trang o dau
        }
        
        if (startIdx >= len) {
            printf("Khong duoc nhap khoang trang! Vui long nhap A, B, C hoac D: ");
            continue;
        }
        
        answer = input[startIdx];  // Lay ky tu dau tien (sau khi bo qua khoang trang)
        
        // VALIDATION 4: Kiem tra co nhieu ky tu khong (chi cho phep 1 ky tu)
        int hasMoreChars = 0;
        for (int i = startIdx + 1; i < len; i++) {
            if (input[i] != ' ' && input[i] != '\t') {
                hasMoreChars = 1;  // Tim thay ky tu thu 2
                break;
            }
        }
        
        if (hasMoreChars) {
            printf("Chi duoc nhap 1 ky tu! Vui long nhap A, B, C hoac D: ");
            continue;
        }
        
        // VALIDATION 5: Chuyen sang chu hoa va kiem tra hop le (A, B, C, D)
        if (normalizeAnswer(&answer)) {
            validInput = 1;  // Dap an hop le, thoat vong lap
        } else {
            printf("Dap an khong hop le! Vui long nhap A, B, C hoac D: ");
        }
    } while (!validInput);  // Lap lai neu chua hop le
    
    // Buoc 3: Kiem tra dap an voi hieu ung dep
    if (answer == question.correctAnswer) {
        printResult(1, question.correctAnswer);  // Hien thi "CHINH XAC!"
        return 1;  // Tra ve 1 neu dung
    } else {
        printResult(0, question.correctAnswer);  // Hien thi "SAI ROI!"
        return 0;  // Tra ve 0 neu sai
    }
}

/**
 * Choi game va tinh diem
 * 
 * THAM SO:
 *   - questions[]: Mang chua tat ca cau hoi
 *   - selectedIndices[]: Mang chua chi so cua cac cau hoi duoc chon (da tron ngau nhien)
 * 
 * RETURN:
 *   - Diem so cuoi cung cua nguoi choi
 * 
 * GIAI THICH:
 * - Ham nay xu ly toan bo qua trinh choi game
 * - Duyet qua tung cau hoi duoc chon
 * - Tinh diem: moi cau dung +1 diem
 * - Hien thi tien do sau moi cau
 * 
 * VI DU:
 *   selectedIndices = [3, 0, 7, 1, ...]  (chi so cau hoi duoc chon)
 *   questions[3] -> Cau hoi thu 4 trong ngan hang
 *   questions[0] -> Cau hoi thu 1 trong ngan hang
 */
int playGame(Question questions[], int selectedIndices[]) {
    int score = 0;          // Diem so hien tai (khoi tao = 0)
    int correctCount = 0;   // So cau dung
    int wrongCount = 0;     // So cau sai
    
    clearScreen();  // Xoa man hinh
    
    // Hien thi man hinh bat dau voi hieu ung dep
    printf("\n");
    printFancyBox(COLOR_BOLD COLOR_CYAN "  BAT DAU TRO CHOI QUIZ!  " COLOR_RESET, 60);
    printf(COLOR_BOLD COLOR_MAGENTA "  |" COLOR_RESET);
    printf(COLOR_WHITE "  Ban se tra loi " COLOR_BOLD COLOR_YELLOW "%d" COLOR_RESET COLOR_WHITE " cau hoi" COLOR_RESET, QUESTIONS_TO_PLAY);
    showSparkles(2);
    printf(COLOR_BOLD COLOR_MAGENTA "                    |\n" COLOR_RESET);
    printf(COLOR_BOLD COLOR_MAGENTA "  |" COLOR_RESET);
    printf(COLOR_GREEN "  * Moi cau dung se duoc +1 diem! *" COLOR_RESET);
    showSparkles(2);
    printf(COLOR_BOLD COLOR_MAGENTA "                    |\n" COLOR_RESET);
    printf(COLOR_BOLD COLOR_MAGENTA "  |" COLOR_RESET);
    printf(COLOR_BOLD COLOR_CYAN "  Chuc ban may man!" COLOR_RESET);
    showSparkles(2);
    printf(COLOR_BOLD COLOR_MAGENTA "                            |\n" COLOR_RESET);
    printf(COLOR_BOLD COLOR_MAGENTA "  +" COLOR_RESET);
    for (int i = 0; i < 58; i++) {
        if (i % 3 == 0) printf(COLOR_CYAN "-" COLOR_RESET);
        else if (i % 3 == 1) printf(COLOR_MAGENTA "-" COLOR_RESET);
        else printf(COLOR_BLUE "-" COLOR_RESET);
    }
    printf(COLOR_BOLD COLOR_MAGENTA "+" COLOR_RESET "\n");
    
    printf("\n");
    printf(COLOR_BOLD COLOR_CYAN "  " COLOR_RESET);
    showLoading("Dang chuan bi cau hoi", 600);  // Hien thi loading animation dep hon
    delay(300);  // Nghi 300ms
    
    // Vong lap: Duyet qua tung cau hoi
    for (int i = 0; i < QUESTIONS_TO_PLAY; i++) {
        int questionIndex = selectedIndices[i];  // Lay chi so cau hoi (da duoc tron ngau nhien)
        
        // Xu ly cau hoi: hien thi, nhan dap an, kiem tra
        // processQuestion tra ve: 1 = dung, 0 = sai
        int isCorrect = processQuestion(questions[questionIndex], i + 1, QUESTIONS_TO_PLAY, score);
        
        // Cap nhat diem va thong ke
        if (isCorrect) {
            score++;           // Tang diem len 1
            correctCount++;    // Tang so cau dung
        } else {
            wrongCount++;      // Tang so cau sai
        }
        
        // Hien thi tien do dep voi progress bar (neu chua phai cau cuoi cung)
        if (i < QUESTIONS_TO_PLAY - 1) {
            printf("\n");
            printf(COLOR_BOLD COLOR_MAGENTA "  +" COLOR_RESET);
            for (int j = 0; j < 56; j++) {
                if (j % 2 == 0) printf(COLOR_CYAN "-" COLOR_RESET);
                else printf(COLOR_MAGENTA "-" COLOR_RESET);
            }
            printf(COLOR_BOLD COLOR_MAGENTA "+" COLOR_RESET "\n");
            
            printf(COLOR_BOLD COLOR_MAGENTA "  |" COLOR_RESET);
            printf(COLOR_BOLD COLOR_MAGENTA "  TIEN DO: " COLOR_RESET);
            printf(COLOR_BOLD COLOR_BLUE "%d/%d" COLOR_RESET, i + 1, QUESTIONS_TO_PLAY);
            printf(COLOR_CYAN "  |  " COLOR_RESET);
            printf(COLOR_BOLD COLOR_GREEN "[OK] Dung: %d" COLOR_RESET, correctCount);
            printf(COLOR_CYAN "  |  " COLOR_RESET);
            printf(COLOR_BOLD COLOR_RED "[X] Sai: %d" COLOR_RESET, wrongCount);
            printf(COLOR_CYAN "  |  " COLOR_RESET);
            printf(COLOR_BOLD COLOR_YELLOW "* Diem: %d/%d" COLOR_RESET, score, i + 1);
            showSparkles(2);
            printf(COLOR_BOLD COLOR_MAGENTA "  |\n" COLOR_RESET);
            
            printf(COLOR_BOLD COLOR_MAGENTA "  |" COLOR_RESET);
            printf(COLOR_BOLD COLOR_CYAN "  " COLOR_RESET);
            showProgressBar(i + 1, QUESTIONS_TO_PLAY, 45);
            printf(COLOR_BOLD COLOR_MAGENTA "  |\n" COLOR_RESET);
            
            printf(COLOR_BOLD COLOR_MAGENTA "  +" COLOR_RESET);
            for (int j = 0; j < 56; j++) {
                if (j % 2 == 0) printf(COLOR_CYAN "-" COLOR_RESET);
                else printf(COLOR_MAGENTA "-" COLOR_RESET);
            }
            printf(COLOR_BOLD COLOR_MAGENTA "+" COLOR_RESET "\n");
            
            printf(COLOR_BOLD COLOR_CYAN "\n  Nhan Enter de tiep tuc..." COLOR_RESET);
            showSparkles(1);
            getchar();   // Doc ky tu '\n' con lai
            getchar();   // Nhan Enter de tiep tuc
        }
    }
    
    return score;  // Tra ve diem so cuoi cung
}

/* ========== CAC HAM QUAN LY FILE (FILE I/O) ========== */
/*
 * GIAI THICH FILE I/O:
 * - FILE: Kieu du lieu de lam viec voi file
 * - fopen(): Mo file (r = read/doc, w = write/ghi, a = append/them vao cuoi)
 * - fclose(): Dong file (QUAN TRONG: phai dong file sau khi dung xong)
 * - fgets(): Doc mot dong tu file
 * - fprintf(): Ghi vao file (giong printf nhung ghi vao file)
 * - fscanf(): Doc tu file (giong scanf nhung doc tu file)
 * 
 * TAI SAO CAN FILE?
 * - De luu tru du lieu lau dai (khi tat chuong trinh, du lieu van con)
 * - Neu khong dung file, du lieu se mat khi tat chuong trinh
 */

/**
 * So sanh diem de sap xep (dung cho qsort - quick sort)
 * 
 * THAM SO:
 *   - a, b: Con tro void (co the tro den bat ky kieu du lieu nao)
 * 
 * GIAI THICH:
 * - qsort(): Ham sap xep co san trong C, can ham so sanh
 * - Ham so sanh phai tra ve:
 *   - So am (< 0): a dung truoc b
 *   - So duong (> 0): a dung sau b
 *   - 0: a bang b
 * 
 * THUAT TOAN:
 * - playerB->score - playerA->score: Sap xep GIAM DAN (diem cao nhat len dau)
 * - Neu muon tang dan: return playerA->score - playerB->score
 * 
 * VI DU:
 *   playerA->score = 5, playerB->score = 8
 *   return 8 - 5 = 3 (> 0) -> playerB dung sau playerA (diem cao hon len dau)
 */
int comparePlayers(const void *a, const void *b) {
    // Ep kieu (cast) tu void* sang Player*
    Player *playerA = (Player *)a;
    Player *playerB = (Player *)b;
    
    // Sap xep giam dan theo diem (diem cao nhat len dau)
    return playerB->score - playerA->score;
}

/**
 * Doc bang xep hang tu file
 * 
 * THAM SO:
 *   - filename: Ten file can doc (vi du: "leaderboard.txt")
 *   - leaderboard[]: Mang de luu du lieu doc duoc
 *   - maxSize: So phan tu toi da cua mang
 * 
 * RETURN:
 *   - So luong nguoi choi doc duoc (neu thanh cong)
 *   - 0 (neu that bai hoac file khong ton tai)
 * 
 * GIAI THICH:
 * - fopen(filename, "r"): Mo file o che do doc (read)
 * - "r": Read mode (chi doc, khong ghi)
 * - NULL: Neu fopen tra ve NULL, file khong ton tai hoac khong mo duoc
 * - fgets(): Doc tung dong tu file
 * 
 * DINH DANG FILE:
 *   Ten nguoi choi 10
 *   Ten khac 8
 *   ...
 */
int loadLeaderboard(const char* filename, Player leaderboard[], int maxSize) {
    // Mo file o che do doc (read)
    FILE *file = fopen(filename, "r");
    
    // Kiem tra neu file khong ton tai hoac khong mo duoc
    if (file == NULL) {
        return 0;  // Tra ve 0 neu that bai
    }
    
    int count = 0;
    char line[200];
    
    // Doc tung dong trong file
    while (count < maxSize && fgets(line, sizeof(line), file) != NULL) {
        // Tim vi tri so diem (so cuoi cung trong dong)
        int len = strlen(line);
        if (len > 0 && line[len-1] == '\n') {
            line[len-1] = '\0';  // Loai bo ky tu xuong dong
        }
        
        // Tim vi tri so diem (tu cuoi len)
        int scoreStart = -1;
        for (int i = len - 2; i >= 0; i--) {
            if (line[i] == ' ' && line[i+1] >= '0' && line[i+1] <= '9') {
                scoreStart = i + 1;
                break;
            }
        }
        
        if (scoreStart > 0) {
            // Tach ten va diem
            line[scoreStart - 1] = '\0';  // Cat chuoi tai vi tri truoc so
            strcpy(leaderboard[count].name, line);
            leaderboard[count].score = atoi(&line[scoreStart]);
            count++;
        }
    }
    
    fclose(file);
    return count;
}

/**
 * Luu bang xep hang vao file (sap xep theo diem)
 */
int saveLeaderboard(const char* filename, Player leaderboard[], int count) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        return 0;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d\n", leaderboard[i].name, leaderboard[i].score);
    }
    
    fclose(file);
    return 1;
}

/**
 * Tao du lieu mau cho bang xep hang (de thay co check)
 */
void createSampleData(const char* filename) {
    FILE *file = fopen(filename, "r");
    // Neu file da ton tai va co du lieu, khong tao lai
    if (file != NULL) {
        fclose(file);
        // Kiem tra file co du lieu khong
        Player temp[MAX_LEADERBOARD];
        int count = loadLeaderboard(filename, temp, MAX_LEADERBOARD);
        if (count > 0) {
            return;  // File da co du lieu, khong tao lai
        }
    }
    
    // Tao du lieu mau
    Player sampleData[] = {
        {"Nguyen Van A", 10},
        {"Tran Thi B", 9},
        {"Le Van C", 8},
        {"Pham Thi D", 7},
        {"Hoang Van E", 6},
        {"Vu Thi F", 5},
        {"Dao Van G", 4},
        {"Bui Thi H", 3},
        {"Dang Van I", 2},
        {"Ngo Thi K", 1}
    };
    
    int sampleCount = sizeof(sampleData) / sizeof(sampleData[0]);
    
    // Sap xep theo diem
    qsort(sampleData, sampleCount, sizeof(Player), comparePlayers);
    
    // Luu vao file
    if (saveLeaderboard(filename, sampleData, sampleCount)) {
        printf("\n[THONG BAO] Da tao du lieu mau cho bang xep hang!\n");
        printf("Co %d nguoi choi mau de thay co kiem tra.\n\n", sampleCount);
    }
}

/**
 * Luu diem vao file (sap xep theo diem cao nhat)
 */
int saveScoreToFile(const char* filename, Player player) {
    Player leaderboard[MAX_LEADERBOARD];
    int count = loadLeaderboard(filename, leaderboard, MAX_LEADERBOARD);
    
    // Them nguoi choi moi
    if (count < MAX_LEADERBOARD) {
        strcpy(leaderboard[count].name, player.name);
        leaderboard[count].score = player.score;
        count++;
    }
    
    // Sap xep theo diem giam dan
    qsort(leaderboard, count, sizeof(Player), comparePlayers);
    
    // Luu lai vao file
    if (saveLeaderboard(filename, leaderboard, count)) {
        printf("Da luu diem vao file %s\n", filename);
        return 1;
    }
    
    return 0;
}

/**
 * Hien thi mot trang cua bang xep hang
 */
void displayLeaderboardPage(Player leaderboard[], int count, int page, int itemsPerPage) {
    int totalPages = (count + itemsPerPage - 1) / itemsPerPage;
    int startIndex = page * itemsPerPage;
    int endIndex = (startIndex + itemsPerPage < count) ? startIndex + itemsPerPage : count;
    
    clearScreen();
    
    // Header box
    char title[100];
    sprintf(title, COLOR_BOLD COLOR_MAGENTA "  BANG XEP HANG - Trang %d/%d  " COLOR_RESET, page + 1, totalPages);
    printBox(title, 60);
    
    // Table header - can chinh chinh xac de bang thang hang
    // Tinh toan: 2 (BOX_V + space) + 5 (STT) + 5 (|) + 30 (Ten) + 5 (|) + 10 (Diem) + 5 (|) + 12 (Xep hang) = 73
    printf(COLOR_CYAN "%s" COLOR_RESET "  ", BOX_V);
    printf(COLOR_BOLD COLOR_YELLOW "%-5s" COLOR_RESET, "STT");
    printf(COLOR_CYAN "  |  " COLOR_RESET);
    printf(COLOR_BOLD COLOR_YELLOW "%-30s" COLOR_RESET, "Ten nguoi choi");
    printf(COLOR_CYAN "  |  " COLOR_RESET);
    printf(COLOR_BOLD COLOR_YELLOW "%10s" COLOR_RESET, "Diem");
    printf(COLOR_CYAN "  |  " COLOR_RESET);
    printf(COLOR_BOLD COLOR_YELLOW "%-12s" COLOR_RESET "\n", "Xep hang");
    printf(COLOR_CYAN "%s", BOX_V);
    for (int i = 0; i < 73; i++) printf(BOX_H);
    printf("%s" COLOR_RESET "\n", BOX_V);
    
    // Hien thi nguoi choi trong trang hien tai
    for (int i = startIndex; i < endIndex; i++) {
        int globalRank = i + 1;
        
        // Mau sac cho STT va badge
        const char* rankColor = (i == 0) ? COLOR_BOLD COLOR_GREEN : 
                               (i == 1) ? COLOR_BOLD COLOR_YELLOW :
                               (i == 2) ? COLOR_BOLD COLOR_CYAN : COLOR_WHITE;
        
        const char* badgeColor = (i == 0) ? COLOR_BOLD COLOR_GREEN :
                                (i == 1) ? COLOR_BOLD COLOR_YELLOW :
                                (i == 2) ? COLOR_BOLD COLOR_CYAN : "";
        
        const char* badgeText = (i == 0) ? "TOP 1" :
                               (i == 1) ? "TOP 2" :
                               (i == 2) ? "TOP 3" : "";
        
        printf(COLOR_CYAN "%s" COLOR_RESET "  ", BOX_V);
        
        // STT voi mau sac - can trai, 5 ky tu
        printf("%s%-5d" COLOR_RESET, rankColor, globalRank);
        printf(COLOR_CYAN "  |  " COLOR_RESET);
        
        // Ten nguoi choi - can trai, 30 ky tu
        printf(COLOR_WHITE "%-30s" COLOR_RESET, leaderboard[i].name);
        printf(COLOR_CYAN "  |  " COLOR_RESET);
        
        // Diem so - can phai, 10 ky tu
        printf(COLOR_BOLD COLOR_GREEN "%10d" COLOR_RESET, leaderboard[i].score);
        printf(COLOR_CYAN "  |  " COLOR_RESET);
        
        // Badge TOP (chi hien thi cho TOP 3) - can trai, 12 ky tu
        if (i < 3) {
            // Badge dep voi format: [ TOP X ] - tong cong 7 ky tu (khong tinh mau)
            printf(badgeColor);
            printf("[ %s ]" COLOR_RESET, badgeText);
            // Them khoang trang de du 12 ky tu (can trai)
            // "[ TOP 1 ]" = 7 ky tu, can them 5 khoang trang
            // "[ TOP 2 ]" = 7 ky tu, can them 5 khoang trang  
            // "[ TOP 3 ]" = 7 ky tu, can them 5 khoang trang
            printf("     ");  // 5 khoang trang
        } else {
            printf("%-12s", "");  // Khoang trang neu khong co badge (12 ky tu)
        }
        
        printf("\n");
        delay(50);
    }
    
    // Footer
    printf(COLOR_CYAN "%s", BOX_BL);
    for (int i = 0; i < 73; i++) printf(BOX_H);
    printf("%s" COLOR_RESET "\n", BOX_BR);
    
    printf("\n");
    printf(COLOR_CYAN "%s" COLOR_RESET "  ", BOX_V);
    printf(COLOR_BLUE "Trang %d/%d" COLOR_RESET, page + 1, totalPages);
    printf(COLOR_CYAN "  |  " COLOR_RESET);
    printf(COLOR_WHITE "Hien thi: %d-%d / %d nguoi choi" COLOR_RESET "\n", 
           startIndex + 1, endIndex, count);
    printf(COLOR_CYAN "%s", BOX_BL);
    for (int i = 0; i < 73; i++) printf(BOX_H);
    printf("%s" COLOR_RESET "\n", BOX_BR);
}

/**
 * Doc va hien thi bang xep hang voi phan trang
 * IMPROVED: Them phan trang de xem duoc tat ca nguoi choi
 */
void displayLeaderboard(const char* filename) {
    Player leaderboard[MAX_LEADERBOARD];
    int count = loadLeaderboard(filename, leaderboard, MAX_LEADERBOARD);
    
    if (count == 0) {
        clearScreen();
        printBox(COLOR_BOLD COLOR_MAGENTA "  BANG XEP HANG  " COLOR_RESET, 50);
        printf(COLOR_CYAN "%s" COLOR_RESET "  ", BOX_V);
        printf(COLOR_YELLOW "Chua co du lieu trong bang xep hang." COLOR_RESET "\n");
        printf(COLOR_CYAN "%s" COLOR_RESET "  ", BOX_V);
        printf(COLOR_WHITE "Hay choi game de them diem vao bang xep hang!" COLOR_RESET "\n");
        printf(COLOR_CYAN "%s", BOX_BL);
        for (int i = 0; i < 48; i++) printf(BOX_H);
        printf("%s" COLOR_RESET "\n", BOX_BR);
        printf(COLOR_BOLD COLOR_CYAN "\nNhan Enter de quay lai..." COLOR_RESET);
        getchar();
        return;
    }
    
    // Sap xep lai de dam bao
    qsort(leaderboard, count, sizeof(Player), comparePlayers);
    
    const int itemsPerPage = 10;  // So nguoi choi moi trang
    int totalPages = (count + itemsPerPage - 1) / itemsPerPage;
    int currentPage = 0;
    char choice;
    
    // Hien thi trang dau tien
    displayLeaderboardPage(leaderboard, count, currentPage, itemsPerPage);
    
    // Neu chi co 1 trang thi khong can phan trang
    if (totalPages <= 1) {
        printf("\n");
        printf(COLOR_BOLD COLOR_CYAN "Nhan Enter de quay lai..." COLOR_RESET);
        getchar();
        getchar();
        return;
    }
    
    // Phan trang neu co nhieu hon 1 trang
    do {
        printf("\n");
        printf(COLOR_CYAN "%s" COLOR_RESET "  ", BOX_V);
        printf(COLOR_BOLD COLOR_GREEN "[P]" COLOR_RESET COLOR_WHITE " Trang truoc" COLOR_RESET);
        printf(COLOR_CYAN "  |  " COLOR_RESET);
        printf(COLOR_BOLD COLOR_GREEN "[N]" COLOR_RESET COLOR_WHITE " Trang sau" COLOR_RESET);
        printf(COLOR_CYAN "  |  " COLOR_RESET);
        printf(COLOR_BOLD COLOR_GREEN "[Q]" COLOR_RESET COLOR_WHITE " Quay lai" COLOR_RESET "\n");
        printf(COLOR_CYAN "%s", BOX_BL);
        for (int i = 0; i < 58; i++) printf(BOX_H);
        printf("%s" COLOR_RESET "\n", BOX_BR);
        printf(COLOR_BOLD COLOR_YELLOW ">>> " COLOR_RESET);
        printf(COLOR_WHITE "Lua chon cua ban: " COLOR_RESET);
        
        choice = getchar();
        while (getchar() != '\n');
        
        choice = (char)toupper(choice);
        
        if (choice == 'N') {
            if (currentPage < totalPages - 1) {
                currentPage++;
                displayLeaderboardPage(leaderboard, count, currentPage, itemsPerPage);
            } else {
                printf(COLOR_RED "\nBan dang o trang cuoi cung!" COLOR_RESET "\n");
                delay(500);
            }
        } else if (choice == 'P') {
            if (currentPage > 0) {
                currentPage--;
                displayLeaderboardPage(leaderboard, count, currentPage, itemsPerPage);
            } else {
                printf(COLOR_RED "\nBan dang o trang dau tien!" COLOR_RESET "\n");
                delay(500);
            }
        } else if (choice == 'Q') {
            break;
        } else {
            printf(COLOR_RED "Lua chon khong hop le! Vui long nhap P, N hoac Q." COLOR_RESET "\n");
            delay(500);
        }
    } while (choice != 'Q');
}

// ========== CAC HAM GIAO DIEN ==========

/**
 * Hien thi giao dien bat dau (cai tien)
 */
void displayWelcome() {
    clearScreen();
    
    // ASCII Art Title dep voi animation
    printAsciiTitle();
    delay(300);
    
    // Fancy box thong tin
    printFancyBox(COLOR_BOLD COLOR_MAGENTA "  QUIZ GAME  " COLOR_RESET, 60);
    printf(COLOR_BOLD COLOR_MAGENTA "  |" COLOR_RESET);
    printf(COLOR_WHITE "            Tro choi cau hoi trac nghiem" COLOR_RESET);
    printf(COLOR_BOLD COLOR_MAGENTA "            |\n" COLOR_RESET);
    printf(COLOR_BOLD COLOR_MAGENTA "  +" COLOR_RESET);
    for (int i = 0; i < 58; i++) printf(COLOR_CYAN "-" COLOR_RESET);
    printf(COLOR_BOLD COLOR_MAGENTA "+" COLOR_RESET "\n");
    
    delay(300);
    
    printf("\n");
    printf(COLOR_BOLD COLOR_GREEN "  ");
    showSparkles(3);
    printf(COLOR_RESET);
    printTyping(COLOR_GREEN "Chao mung ban den voi Quiz Game!" COLOR_RESET, 20);
    printf(COLOR_BOLD COLOR_GREEN " ");
    showSparkles(3);
    printf(COLOR_RESET "\n");
    delay(200);
    
    printf("\n");
    printf(COLOR_BOLD COLOR_CYAN "  +- " COLOR_RESET);
    printf(COLOR_WHITE "Ban se tra loi " COLOR_BOLD COLOR_YELLOW "%d" COLOR_RESET COLOR_WHITE " cau hoi ngau nhien" COLOR_RESET "\n", QUESTIONS_TO_PLAY);
    printf(COLOR_BOLD COLOR_CYAN "  +- " COLOR_RESET);
    printf(COLOR_WHITE "Moi cau dung se duoc " COLOR_BOLD COLOR_GREEN "+1 diem" COLOR_RESET "\n");
    printf(COLOR_BOLD COLOR_CYAN "  +- " COLOR_RESET);
    printf(COLOR_BOLD COLOR_CYAN "Chuc ban may man!" COLOR_RESET);
    showSparkles(3);
    printf("\n");
    
    printf("\n");
    printf(COLOR_BOLD COLOR_MAGENTA "  " COLOR_RESET);
    for (int i = 0; i < 55; i++) {
        if (i % 3 == 0) printf(COLOR_YELLOW "=" COLOR_RESET);
        else if (i % 3 == 1) printf(COLOR_MAGENTA "=" COLOR_RESET);
        else printf(COLOR_CYAN "=" COLOR_RESET);
        delay(3);
    }
    printf("\n\n");
    delay(500);
}

/**
 * Nhap ten nguoi choi voi validation
 */
void getPlayerName(Player *player) {
    int validName = 0;
    
    printf("\n");
    printBox(COLOR_BOLD COLOR_MAGENTA "  NHAP TEN  " COLOR_RESET, 50);
    
    do {
        printf(COLOR_CYAN "%s" COLOR_RESET "  ", BOX_V);
        printf(COLOR_BOLD COLOR_YELLOW ">>> " COLOR_RESET);
        printf(COLOR_WHITE "Nhap ten cua ban: " COLOR_RESET);
        
        if (fgets(player->name, MAX_NAME_LENGTH, stdin) == NULL) {
            printf(COLOR_RED "Loi khi nhap ten! Vui long thu lai." COLOR_RESET "\n");
            continue;
        }
        
        player->name[strcspn(player->name, "\n")] = 0;
        trimString(player->name);
        
        if (isValidName(player->name)) {
            validName = 1;
            printf(COLOR_CYAN "%s", BOX_BL);
            for (int i = 0; i < 48; i++) printf(BOX_H);
            printf("%s" COLOR_RESET "\n", BOX_BR);
        } else {
            printf(COLOR_CYAN "%s" COLOR_RESET "  ", BOX_V);
            printf(COLOR_RED "Ten khong hop le! Vui long nhap lai." COLOR_RESET "\n");
            printf(COLOR_CYAN "%s" COLOR_RESET "  ", BOX_V);
            printf(COLOR_YELLOW "(Ten khong duoc rong, khong qua %d ky tu)" COLOR_RESET "\n", MAX_NAME_LENGTH - 1);
        }
    } while (!validName);
}

/**
 * Hien thi thong bao danh gia ket qua
 */
void displayPerformanceMessage(int score, int total) {
    double percentage = (double)score / total * 100;
    
    printf("\n");
    if (percentage == 100) {
        printBox(COLOR_BOLD COLOR_GREEN "  XUAT SAC!  " COLOR_RESET, 50);
        printf(COLOR_CYAN "%s" COLOR_RESET "  ", BOX_V);
        printf(COLOR_GREEN COLOR_BOLD "Ban da tra loi dung TAT CA!" COLOR_RESET "\n");
        printf(COLOR_CYAN "%s" COLOR_RESET "  ", BOX_V);
        printf(COLOR_YELLOW "Ban la mot chuyen gia thuc su!" COLOR_RESET "\n");
    } else if (percentage >= 80) {
        printBox(COLOR_BOLD COLOR_GREEN "  XUAT SAC!  " COLOR_RESET, 50);
        printf(COLOR_CYAN "%s" COLOR_RESET "  ", BOX_V);
        printf(COLOR_GREEN COLOR_BOLD "Ban tra loi dung %d/%d cau!" COLOR_RESET "\n", score, total);
        printf(COLOR_CYAN "%s" COLOR_RESET "  ", BOX_V);
        printf(COLOR_YELLOW "Ban co kien thuc rat tot!" COLOR_RESET "\n");
    } else if (percentage >= 60) {
        printBox(COLOR_BOLD COLOR_BLUE "  TOT LAM!  " COLOR_RESET, 50);
        printf(COLOR_CYAN "%s" COLOR_RESET "  ", BOX_V);
        printf(COLOR_BLUE "Ban tra loi dung %d/%d cau." COLOR_RESET "\n", score, total);
        printf(COLOR_CYAN "%s" COLOR_RESET "  ", BOX_V);
        printf(COLOR_WHITE "Tiep tuc co gang nhe!" COLOR_RESET "\n");
    } else if (percentage >= 40) {
        printBox(COLOR_BOLD COLOR_YELLOW "  KHA!  " COLOR_RESET, 50);
        printf(COLOR_CYAN "%s" COLOR_RESET "  ", BOX_V);
        printf(COLOR_YELLOW "Ban tra loi dung %d/%d cau." COLOR_RESET "\n", score, total);
        printf(COLOR_CYAN "%s" COLOR_RESET "  ", BOX_V);
        printf(COLOR_WHITE "On lai va thu lai nhe!" COLOR_RESET "\n");
    } else {
        printBox(COLOR_BOLD COLOR_RED "  CO GANG HON!  " COLOR_RESET, 50);
        printf(COLOR_CYAN "%s" COLOR_RESET "  ", BOX_V);
        printf(COLOR_RED "Ban tra loi dung %d/%d cau." COLOR_RESET "\n", score, total);
        printf(COLOR_CYAN "%s" COLOR_RESET "  ", BOX_V);
        printf(COLOR_WHITE "Dung bo cuoc, hay thu lai!" COLOR_RESET "\n");
    }
    printf(COLOR_CYAN "%s", BOX_BL);
    for (int i = 0; i < 48; i++) printf(BOX_H);
    printf("%s" COLOR_RESET "\n", BOX_BR);
    delay(1000);
}

/**
 * Hien thi ket qua game (cai tien)
 */
void displayResult(Player player) {
    clearScreen();
    
    // Result box dep voi ASCII art
    printf("\n");
    printf(COLOR_BOLD COLOR_MAGENTA);
    printf("  +=======================================================+\n");
    printf("  |" COLOR_RESET);
    printf(COLOR_BOLD COLOR_CYAN "                  KET QUA CUA BAN" COLOR_RESET);
    printf(COLOR_BOLD COLOR_MAGENTA "                  |\n");
    printf("  +=======================================================+\n");
    printf("  |" COLOR_RESET);
    printf(COLOR_WHITE "  Ten nguoi choi: " COLOR_BOLD COLOR_CYAN "%s" COLOR_RESET, player.name);
    printf(COLOR_BOLD COLOR_MAGENTA "                        |\n");
    printf("  |" COLOR_RESET);
    printf(COLOR_WHITE "  So cau dung:   " COLOR_BOLD COLOR_GREEN "%d/%d" COLOR_RESET, player.score, QUESTIONS_TO_PLAY);
    printf(COLOR_BOLD COLOR_MAGENTA "                        |\n");
    printf("  |" COLOR_RESET);
    printf(COLOR_WHITE "  Phan tram:     " COLOR_BOLD COLOR_YELLOW "%.1f%%" COLOR_RESET, (double)player.score / QUESTIONS_TO_PLAY * 100);
    printf(COLOR_BOLD COLOR_MAGENTA "                        |\n");
    printf("  +=======================================================+\n" COLOR_RESET);
    
    printf("\n");
    displayPerformanceMessage(player.score, QUESTIONS_TO_PLAY);
}

/**
 * Hien thi thong bao ket thuc
 */
void displayGoodbye() {
    clearScreen();
    
    printf("\n\n");
    printf(COLOR_BOLD COLOR_MAGENTA);
    printf("  +=======================================================+\n");
    printf("  |" COLOR_RESET);
    printf(COLOR_BOLD COLOR_CYAN "                      TAM BIET" COLOR_RESET);
    printf(COLOR_BOLD COLOR_MAGENTA "                      |\n");
    printf("  +=======================================================+\n");
    printf("  |" COLOR_RESET);
    printf(COLOR_BOLD COLOR_MAGENTA "  " COLOR_RESET);
    printTyping(COLOR_GREEN "* Cam on ban da tham gia Quiz Game! *" COLOR_RESET, 25);
    printf(COLOR_BOLD COLOR_MAGENTA "  |\n");
    printf("  |" COLOR_RESET);
    printf(COLOR_BOLD COLOR_MAGENTA "  " COLOR_RESET);
    printTyping(COLOR_CYAN "* Hen gap lai ban lan sau! *" COLOR_RESET, 25);
    printf(COLOR_BOLD COLOR_MAGENTA "  |\n");
    printf("  +=======================================================+\n" COLOR_RESET);
    
    printf("\n");
    printf(COLOR_BOLD COLOR_YELLOW "  " COLOR_RESET);
    for (int i = 0; i < 55; i++) {
        printf(COLOR_YELLOW "=" COLOR_RESET);
        delay(5);
    }
    printf("\n\n");
    delay(500);
}

/**
 * Hien thi menu chinh
 */
void displayMainMenu() {
    clearScreen();
    
    // Fancy menu header
    printf("\n");
    printFancyBox(COLOR_BOLD COLOR_CYAN "  MENU CHINH  " COLOR_RESET, 60);
    
    // Menu items voi icon dep va animation - dung ASCII
    printf(COLOR_BOLD COLOR_MAGENTA "  |" COLOR_RESET);
    printf(COLOR_BOLD COLOR_GREEN "  [1]" COLOR_RESET);
    printf(COLOR_WHITE "  Choi game" COLOR_RESET);
    showSparkles(2);
    printf(COLOR_BOLD COLOR_MAGENTA "                              |\n" COLOR_RESET);
    delay(120);
    
    printf(COLOR_BOLD COLOR_MAGENTA "  |" COLOR_RESET);
    printf(COLOR_BOLD COLOR_GREEN "  [2]" COLOR_RESET);
    printf(COLOR_WHITE "  Xem bang xep hang" COLOR_RESET);
    showSparkles(2);
    printf(COLOR_BOLD COLOR_MAGENTA "                      |\n" COLOR_RESET);
    delay(120);
    
    printf(COLOR_BOLD COLOR_MAGENTA "  |" COLOR_RESET);
    printf(COLOR_BOLD COLOR_GREEN "  [3]" COLOR_RESET);
    printf(COLOR_WHITE "  Thoat" COLOR_RESET);
    showSparkles(2);
    printf(COLOR_BOLD COLOR_MAGENTA "                              |\n" COLOR_RESET);
    delay(120);
    
    printf(COLOR_BOLD COLOR_MAGENTA "  +" COLOR_RESET);
    for (int i = 0; i < 58; i++) {
        if (i % 2 == 0) printf(COLOR_CYAN "-" COLOR_RESET);
        else printf(COLOR_MAGENTA "-" COLOR_RESET);
    }
    printf(COLOR_BOLD COLOR_MAGENTA "+" COLOR_RESET "\n");
    
    printf("\n");
    printf(COLOR_BOLD COLOR_YELLOW "  === " COLOR_RESET);
    printf(COLOR_WHITE "Nhap lua chon cua ban " COLOR_RESET);
    printf(COLOR_BOLD COLOR_CYAN "(1/2/3)" COLOR_RESET);
    printf(COLOR_WHITE ": " COLOR_RESET);
}

/**
 * Nhap lua chon menu
 */
int getMenuChoice() {
    int choice;
    char input[10];
    
    do {
        if (fgets(input, sizeof(input), stdin) == NULL) {
            return 0;
        }
        
        choice = atoi(input);
        
        if (choice >= 1 && choice <= 3) {
            return choice;
        } else {
            printf("Lua chon khong hop le! Vui long nhap 1, 2 hoac 3: ");
        }
    } while (1);
}

/**
 * Ham choi game (tach ra de de quan ly)
 */
void playGameMode(Question questions[], int selectedIndices[]) {
    Player player;
    
    // Nhap ten nguoi choi
    getPlayerName(&player);
    
    // Chon cau hoi va choi game
    selectRandomQuestions(selectedIndices, MAX_QUESTIONS, QUESTIONS_TO_PLAY);
    player.score = playGame(questions, selectedIndices);
    
    // Hien thi ket qua
    displayResult(player);
    
    // Luu diem
    saveScoreToFile(LEADERBOARD_FILE, player);
    
    // Hien thi bang xep hang sau khi choi
    printf("\n");
    displayLeaderboard(LEADERBOARD_FILE);
    
    printf("\nNhan Enter de quay ve menu chinh...");
    getchar();
    getchar();  // Nhan Enter
}

/* ========== HAM MAIN - DIEM BAT DAU CUA CHUONG TRINH ========== */
/*
 * GIAI THICH HAM MAIN:
 * - main() la ham dac biet, la noi chuong trinh bat dau chay
 * - int main(): Ham tra ve so nguyen (0 = thanh cong, khac 0 = loi)
 * - return 0: Bao hieu chuong trinh chay thanh cong
 * 
 * LUU Y:
 * - Moi chuong trinh C phai co ham main()
 * - Ham main la ham dau tien duoc goi khi chay chuong trinh
 */

/**
 * Ham main - Diem bat dau cua chuong trinh
 * 
 * QUY TRINH HOAT DONG:
 * 1. Khoi tao he thong (console, random)
 * 2. Khoi tao ngan hang cau hoi
 * 3. Hien thi menu chinh
 * 4. Lap lai cho den khi nguoi choi chon thoat:
 *    - Neu chon 1: Choi game
 *    - Neu chon 2: Xem bang xep hang
 *    - Neu chon 3: Thoat
 */
int main() {
    /* ========== BUOC 1: KHOI TAO HE THONG ========== */
    setupConsole();        // Set UTF-8 de hien thi tieng Viet co dau
    initializeRandom();    // Khoi tao seed cho ham random
    
    /* ========== BUOC 2: KHAI BAO BIEN ========== */
    Question questions[MAX_QUESTIONS];           // Mang luu 10 cau hoi
    int selectedIndices[QUESTIONS_TO_PLAY];      // Mang luu chi so cau hoi duoc chon
    int choice;                                  // Lua chon cua nguoi choi (1, 2, hoac 3)
    
    /* ========== BUOC 3: KHOI TAO DU LIEU ========== */
    initializeQuestions(questions);              // Khoi tao 10 cau hoi vao mang questions
    
    // Tao du lieu mau cho bang xep hang (neu file chua co du lieu)
    createSampleData(LEADERBOARD_FILE);
    
    /* ========== BUOC 4: GIAO DIEN BAT DAU ========== */
    displayWelcome();  // Hien thi man hinh chao mung
    
    /* ========== BUOC 5: VONG LAP MENU CHINH ========== */
    // Do-while: Lap lai cho den khi choice = 3 (thoat)
    do {
        displayMainMenu();        // Hien thi menu: 1. Choi game, 2. Xem BXH, 3. Thoat
        choice = getMenuChoice(); // Nhan lua chon tu nguoi choi
        
        // Switch-case: Kiem tra lua chon va thuc hien hanh dong tuong ung
        switch (choice) {
            case 1:  // Nguoi choi chon "Choi game"
                playGameMode(questions, selectedIndices);  // Bat dau choi game
                break;  // Thoat khoi switch
                
            case 2:  // Nguoi choi chon "Xem bang xep hang"
                displayLeaderboard(LEADERBOARD_FILE);  // Hien thi bang xep hang
                printf("\nNhan Enter de quay ve menu chinh...");
                getchar();   // Doc ky tu '\n' con lai trong buffer
                getchar();   // Nhan Enter de quay ve menu
                break;
                
            case 3:  // Nguoi choi chon "Thoat"
                displayGoodbye();  // Hien thi thong bao tam biet
                break;
                
            default:  // Neu lua chon khong phai 1, 2, hoac 3
                printf("Lua chon khong hop le!\n");
                break;
        }
    } while (choice != 3);  // Lap lai neu choice != 3 (chua chon thoat)
    
    /* ========== BUOC 6: KET THUC CHUONG TRINH ========== */
    return 0;  // Tra ve 0 = chuong trinh chay thanh cong
}
