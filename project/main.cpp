// 制限時間内に乗客(P)をピックアップしゴール(GOAL)に連れて行くゲーム
// 制限時間をオーバーするか燃料がなくなったらゲームオーバー
// 燃料は1回の移動ごとに速度に応じて消費する
// SPEED=1:5,SPEED=2:7,SPEED=3:10,SPEED=4:15,SPEED=5:20
// 乗客を乗せた後チェックポイント(CP)を通過する必要がある(乗客を乗せる前にチェックポイントに停止してもミッション達成にはならない)
// 1回の移動で2分経過する
// ガソリンスタンド(GS)に停止すると5分経過し燃料が20回復する
// ガソリンスタンドには何回も停止できる
// 各ランドマークにはぴったり止まらなければならない

#include <iostream>
#include <stdexcept>
#include <string>
#include <random>

std::string map_info[10][10];
int map_size = 10;        // 地図エリアのサイズ、ここを変更する場合はmap_infoも変更すること
int car_x = 1;            // 初期の車の位置座標x
int car_y = map_size - 2; // 初期の車の位置座標y
char car_direction = 'n'; // 初期の車の向いている方角
int speed = 1;            // 初期の車の速度, MAX=5 MIN=1
int fuel = 100;           // 残り燃料, MAX=100
int flag = 0;             // 終了フラグ
int limit_time = 60;      // 制限時間
int mission = 0;          // ミッション達成状況
int GS_x;                 // ガソリンスタンドのx座標
int GS_y;                 // ガソリンスタンドのy座標
int CP1_x;                // チェックポイントのx座標
int CP1_y;                // チェックポイントのy座標
int CP2_x;                // チェックポイントのx座標
int CP2_y;                // チェックポイントのy座標
int P_x;                  // 乗客のx座標
int P_y;                  // 乗客のy座標
int rand_on = 0;          // ランドマーク再表示判断情報

// 地図を表示する
void map()
{
    for (int y = 0; y < map_size; y++)
    {
        for (int x = 0; x < map_size; x++)
        {
            std::cout << map_info[x][y];
        }
        std::cout << "\n";
    }
}

// 地図上にランドマークをランダムに配置する
void set_randmark()
{
    std::random_device rd;
    std::uniform_int_distribution<int> dist(2, map_size - 3);
    std::mt19937 gen(rd());
    int a=0;

    while(a == 0){
    GS_x = dist(gen);
    GS_y = dist(gen);
    CP1_x = dist(gen);
    CP1_y = dist(gen);
    CP2_x = dist(gen);
    CP2_y = dist(gen);
    P_x = dist(gen);
    P_y = dist(gen);

    if((GS_x == CP1_x && GS_y == CP1_y) || (GS_x == CP2_x && GS_y == CP2_y) || (GS_x == P_x && GS_y == P_y) || (CP1_x == CP2_x && CP1_y == CP2_y) || (CP1_x == P_x && CP1_y == P_y) || (CP2_x == P_x && CP2_y == P_y)){
        a = 0;
    }
    else{
        a = 1;
    }
    }

    map_info[GS_x][GS_y] = " GS ";
    map_info[CP1_x][CP1_y] = " CP ";
    map_info[CP2_x][CP2_y] = " CP ";
    map_info[P_x][P_y] = " P  ";

}

// ランドマーク再格納
void reset_randmark()
{
    if (rand_on == 1)
    {
        if (((car_x == CP1_x) && (car_y == CP1_y)) || ((car_x == CP2_x) && (car_y == CP2_y)))
        {
            map_info[car_x][car_y] = " CP ";
            rand_on = 0;
        }
        else if ((car_x == GS_x) && (car_y == GS_y))
        {
            map_info[car_x][car_y] = " GS ";
            rand_on = 0;
        }
    }
}

// 燃料消費
void use_fuel()
{
    switch (speed)
    {
    case 1:
        fuel = fuel - 5;
        break;
    case 2:
        fuel = fuel - 7;
        break;
    case 3:
        fuel = fuel - 10;
        break;
    case 4:
        fuel = fuel - 15;
        break;
    case 5:
        fuel = fuel - 20;
        break;
    }
}

// 時間消費
void use_time()
{
    if ((car_x == GS_x) && (car_y == GS_y))
    {
        limit_time = limit_time - 5;
    }
    else
    {
        limit_time = limit_time - 2;
    }
}

// 車の現在位置情報を消去する
void delete_car_now()
{
    map_info[car_x][car_y] = "    ";
}

// 上に進む
void go_up()
{
    delete_car_now();
    reset_randmark();
    car_y = car_y - speed;
    map_info[car_x][car_y] = " C^ ";
    use_fuel();
    use_time();
}
// 右に進む
void go_right()
{
    delete_car_now();
    reset_randmark();
    car_x = car_x + speed;
    map_info[car_x][car_y] = " C> ";
    use_fuel();
    use_time();
}

// 左に進む
void go_left()
{
    delete_car_now();
    reset_randmark();
    car_x = car_x - speed;
    map_info[car_x][car_y] = " <C ";
    use_fuel();
    use_time();
}

// 下に進む
void go_down()
{
    delete_car_now();
    reset_randmark();
    car_y = car_y + speed;
    map_info[car_x][car_y] = " Cv ";
    use_fuel();
    use_time();
}

// 直進する
void go_straight()
{
    if (car_direction == 'n')
    {
        go_up();
    }
    else if (car_direction == 'e')
    {
        go_right();
    }
    else if (car_direction == 's')
    {
        go_down();
    }
    else if (car_direction == 'w')
    {
        go_left();
    }
}

// 加速する
void go_accelerate()
{
    speed = speed + 1;
}

// 減速する
void go_decelerate()
{
    speed = speed - 1;
}

// 停止する
void go_stop()
{
    use_time();
}

// ゴール可否チェック
void check_goal()
{
    if ((car_x == (map_size - 2)) && car_y == 1 && mission == 3 && (fuel > 0) && (limit_time > 0))
    {
        flag = 1;
        std::cout << "GOAL!!" << std::endl;
    }
}

// ゲームオーバーチェック
void check_gameover()
{
    if (fuel < 0 || limit_time < 0)
    {
        flag = 1;
        std::cout << "GAME OVER!! Let's Try Again!" << std::endl;
    }
}

// 入力チェック
int check_input(std::string con)
{
    if (con == "R")
    {
        if (((car_direction == 'n') && ((car_x + speed) > (map_size - 2))) || ((car_direction == 'e') && ((car_y + speed) > (map_size - 2))) || ((car_direction == 's') && ((car_x - speed) < 1)) || ((car_direction == 'w') && ((car_y - speed) < 1)))
        {
            std::cout << "Over The Area!! Please Input Again!" << std::endl;
            return 1;
        }
    }
    else if (con == "L")
    {
        if (((car_direction == 'n') && ((car_x - speed) < 1)) || ((car_direction == 'e') && ((car_y - speed) < 1)) || ((car_direction == 's') && ((car_x + speed) > (map_size - 2))) || ((car_direction == 'w') && ((car_x + speed) > (map_size - 2))))
        {
            std::cout << "Over The Area!! Please Input Again!" << std::endl;
            return 1;
        }
    }
    else if (con == "S")
    {
        if (((car_direction == 'e') && ((car_x + speed) > (map_size - 2))) || ((car_direction == 'w') && ((car_x - speed) < 1)) || ((car_direction == 's') && ((car_y + speed) > (map_size - 2))) || ((car_direction == 'n') && ((car_y - speed) < 1)))
        {
            std::cout << "Over The Area!! Please Input Again!" << std::endl;
            return 1;
        }
    }
    else if (con == "A")
    {
        if ((speed + 1) > 6)
        {
            std::cout << "SPEED is MAX!! Please Input Again!" << std::endl;
            return 1;
        }
        else if (((car_direction == 'e') && ((car_x + speed + 1) > (map_size - 2))) || ((car_direction == 'w') && ((car_x - speed - 1) < 1)) || ((car_direction == 's') && ((car_y + speed + 1) > (map_size - 2))) || ((car_direction == 'n') && ((car_y - speed - 1) < 1)))
        {
            std::cout << "Over The Area!! Please Input Again!" << std::endl;
            return 1;
        }
    }
    else if (con == "D")
    {
        if ((speed - 1) < 1)
        {
            std::cout << "SPEED is MIN!! Please Input Again!" << std::endl;
            return 1;
        }
        else if (((car_direction == 'e') && ((car_x + speed - 1) > (map_size - 2))) || ((car_direction == 'w') && ((car_x - speed + 1) < 1)) || ((car_direction == 's') && ((car_y + speed - 1) > (map_size - 2))) || ((car_direction == 'n') && ((car_y - speed + 1) < 1)))
        {
            std::cout << "Over The Area!! Please Input Again!" << std::endl;
            return 1;
        }
    }
    else if ((con != "L") && (con != "R") && (con != "S") && (con != "A") && (con != "D") && (con != "T"))
    {
        std::cout << "Input Error!! Please Input Again!" << std::endl;
        return 1;
    }
    return 0;
}

// ランドマークチェック
void check_randmark()
{
    if ((car_x == P_x) && (car_y == P_y))
    {
        mission = mission + 1;
    }
    else if ((((car_x == CP1_x) && (car_y == CP1_y)) || ((car_x == CP2_x) && (car_y == CP2_y))) && (mission == 0))
    {
        rand_on = 1;
    }
    else if ((((car_x == CP1_x) && (car_y == CP1_y)) || ((car_x == CP2_x) && (car_y == CP2_y))) && (mission > 0))
    {
        mission = mission + 1;
    }
    else if ((car_x == GS_x) && (car_y == GS_y))
    {
        if (fuel < 100)
        {
            fuel = fuel + 20;
            if (fuel > 100)
            {
                fuel = 100;
            }
        }

        rand_on = 1;
    }
}

int main()
{
    // 地図初期配置
    for (int y = 0; y < map_size; y++)
    {
        for (int x = 0; x < map_size; x++)
        {
            map_info[x][y] = "    ";
        }
    }
    map_info[0][0] = '+';
    map_info[(map_size - 1)][0] = '+';
    map_info[0][(map_size - 1)] = 'S';
    map_info[(map_size - 1)][(map_size - 1)] = '+';
    for (int x = 1; x < (map_size - 1); x++)
    {
        map_info[x][0] = " -- ";
    }
    for (int x = 1; x < (map_size - 1); x++)
    {
        map_info[x][(map_size - 1)] = " -- ";
    }
    for (int y = 1; y < (map_size - 1); y++)
    {
        map_info[0][y] = '|';
    }
    for (int y = 1; y < (map_size - 1); y++)
    {
        map_info[(map_size - 1)][y] = '|';
    }
    map_info[1][(map_size - 1)] = "TART";
    map_info[(map_size - 2)][0] = "GOAL";
    map_info[1][(map_size - 2)] = " C^ ";

    // ランドマークを配置
    set_randmark();

    // 初期地図を表示
    map();

    // 初期速度の表示
    std::cout << "SPEED is " << speed << std::endl;

    // 初期燃料の表示
    std::cout << "FUEL is " << fuel << std::endl;

    // ミッションを達成するかゲームオーバーになるまでループ
    while (flag == 0)
    {
        // 入力を求める
        std::string control;
        std::cout << "Input Car Control!"
                  << "\n";
        std::cout << "(turn left -> L | turn right -> R | continue straight -> S | accelerate -> A | decelerate -> D | stop -> T)" << std::endl;
        std::cin >> control;

        // 入力チェック
        if (check_input(control) == 1)
        {
            continue;
        }

        // 移動
        if (control == "R")
        {
            if (car_direction == 'n')
            {
                go_right();
                car_direction = 'e';
            }
            else if (car_direction == 'e')
            {
                go_down();
                car_direction = 's';
            }
            else if (car_direction == 's')
            {
                go_left();
                car_direction = 'w';
            }
            else if (car_direction == 'w')
            {
                go_up();
                car_direction = 'n';
            }
        }
        else if (control == "L")
        {
            if (car_direction == 'n')
            {
                go_left();
                car_direction = 'w';
            }
            else if (car_direction == 'e')
            {
                go_up();
                car_direction = 'n';
            }
            else if (car_direction == 's')
            {
                go_right();
                car_direction = 'e';
            }
            else if (car_direction == 'w')
            {
                go_down();
                car_direction = 's';
            }
        }
        else if (control == "S")
        {
            go_straight();
        }
        else if (control == "T")
        {
            go_stop();
        }
        else if (control == "A")
        {
            go_accelerate();
            go_straight();
        }
        else if (control == "D")
        {
            go_decelerate();
            go_straight();
        }

        check_randmark();

        // 入力後の地図を表示
        map();

        // 速度の表示
        std::cout << "NOW SPEED is " << speed << std::endl;

        // 燃料の表示
        std::cout << "NOW FUEL is " << fuel << std::endl;

        // 残り時間の表示
        std::cout << "Remaining TIME is " << limit_time << std::endl;

        // ゴール判定
        check_goal();

        // GAME OVER判定
        check_gameover();
    }

    return 0;
}