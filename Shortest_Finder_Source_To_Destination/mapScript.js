var dx = new Array()
var dy = new Array()
dx = [0,0,1,-1]
dy = [1,-1,0,0]

var visit = new Array()
var pre_x = new Array()
var pre_y = new Array()
var post_x = new Array()
var post_y = new Array()
var level = new Array()
var visit_road = new Array()

var cnt1 = 0;
var cnt2 = 0;

for(let i = 0; i < 49; i++){
    visit[i] = new Array();
    pre_x[i] = new Array();
    pre_y[i] = new Array();
    level[i] = new Array();
    post_x[i] = new Array();
    post_y[i] = new Array();
    visit_road[i] = new Array();
}

function fun(x,y){
    result = "road_" + String(x) + "," + String(y);
    val = document.getElementById(result).ariaValueMax;

    for(let i = 0; i < 4; i++){
        change_color(x+dx[i],y+dy[i]);
    }

    let flag = 1;
    if(check_string_cordinate()==1){
        path_reset();
        s_x = document.getElementById('s_x').value;
        s_y = document.getElementById('s_y').value;
        s_x = parseInt(s_x);
        s_y = parseInt(s_y);
        t_s_x = s_x;
        t_s_y = s_y;
        s_x = x;
        s_y = y;
        x = t_s_x;
        y = t_s_y;
        engin(x,y,s_x,s_y,"find");
        engin(x,y,s_x,s_y,"set");
        set_cordinate(s_x,s_y);
    }else{
        s_x = 5;
        s_y = 9;
        set_cordinate(x,y);
        res1 = engin(x,y,5,9,"find");
        res2 = engin(x,y,7,7,"find");
        res3 = engin(x,y,5,5,"find");
        console.log("result-------",result,res1,res2);

        if(res1<=res2 && res1<=res2)engin(5,8,x,y,"set");
        else if(res2<=res1 && res2 <= res2)engin(6,7,x,y,"set");
        else engin(5,6,x,y,"set");
    }
}

function check_string_cordinate(){
    s_x = document.getElementById('s_x').value;
    s_y = document.getElementById('s_y').value;
    if(s_x==-1 || s_y==-1){
        return 0;
    }else return 1;
}

function set_cordinate(x,y){
    document.getElementById('s_x').value = x;
    document.getElementById('s_y').value = y;
}

function engin(x,y,s_x,s_y,per){
        find_path_cordinate();
        visit[x][y] = 0;
        dfs(s_x,s_y,s_x,s_y,x,y,0);
        if(per=="find")return find_path(x,y,s_x,s_y);
        else{
            console.log(s_x,s_y);
            set_graph_path(x,y,s_x,s_y);
        }
}

function change_color(x,y){
    result = String(x),+"," + String(y);
    document.getElementById(result).style='background-color: #8e44ad';
}

function find_path_cordinate(){
    let cnt = 0; 
    for(let i = 0; i< 49; i++){
        for(let j = 0; j < 49; j++){
            div_id = String(i)+"," + String(j);
            result = "road_" + div_id;
            visit[i][j] = 1;
            level[i][j] = 0;
            pre_x[i][j] = -1;
            pre_y[i][j] = -1;

            visit_road[i][j] = 0;

            let val = document.getElementById(result).value;
            if(val==1){
                cnt++;
                visit[i][j] = 0;
            }
        }
    }
}

function dfs(x,y,x1,y1,tx,ty,lev){
    if(x<0 || y<0 || x>49 || y>49)return;
    if(visit[x][y]==1 && level[x][y]<=lev)return;
    visit[x][y] = 1;
    
}