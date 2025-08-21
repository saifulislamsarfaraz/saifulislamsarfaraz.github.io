
var dx = new Array();
dx = [0,0,1,-1];
var dy = new Array();
dy = [1,-1,0,0];
var visit = new Array();
var pre_x = new Array();
var pre_y = new Array();
var post_x = new Array();
var post_y = new Array();
var level = new Array();
var visit_road = new Array();
var c=0,c1=0;
for(i=0; i<49; i++){
    visit[i]=new Array(),
    pre_x[i]=new Array(),
    pre_y[i]=new Array();
    level[i]=new Array();
    visit_road[i]=new Array();
    post_x[i]=new Array();
    post_y[i]=new Array();
} 


    function fun(x,y){
       
        res="road_"+String(x)+","+String(y);
        val=document.getElementById(res).value;
        for(i=0; i<4; i++){
            change_color(x+dx[i],y+dy[i],x,y);
        }
        flag=1;

        if(cheikh_sarting_cordinate()==1){
           reset_path();
           s_x=document.getElementById('s_x').value;
           s_y=document.getElementById('s_y').value;
           s_x=parseInt(s_x);
           s_y=parseInt(s_y); 
           t_s_x=s_x;
           t_s_y=s_y;
           s_x=x;
           s_y=y;
           x=t_s_x;
           y=t_s_y;
           engin(x,y,s_x,s_y,"find");
           engin(x,y,s_x,s_y,"set");
           set_cordinate(s_x,s_y);
        }
        else {
          s_x=5;
          s_y=9;
          set_cordinate(x,y);
          res1=engin(x,y,5,9,"find");
          res2=engin(x,y,7,7,"find");
          res3=engin(x,y,5,5,"find");
          console.log("result--------",res,res1,res2);
       
          if(res1<=res2 && res1<=res2)engin(5,8,x,y,"set");
          else if(res2<=res1 && res2<=res3)engin(6,7,x,y,"set");
          else engin(5,6,x,y,"set");
      }
    }


    function cheikh_sarting_cordinate(){
      s_x=document.getElementById('s_x').value;
      s_y=document.getElementById('s_y').value;
      if(s_x==-1 || s_y==-1)return 0;
      return 1;
    }

    function set_cordinate(x,y){
      
      document.getElementById('s_x').value=x;
      document.getElementById('s_y').value=y;

    }

    function engin(x,y,s_x,s_y,per){
        
        find_path_cordinate();
        visit[x][y]=0;
        dfs(s_x,s_y,s_x,s_y,x,y,0);
        if(per=="find")return find_path(x,y,s_x,s_y);
        else {
          console.log(s_x,s_y);
          set_graph_path(x,y,s_x,s_y);
    }
}
    function change_color(x,y){
        res=String(x)+","+String(y);
        document.getElementById(res).style='background-color: green';
    }

    function find_path_cordinate(){
      c=0;
      for(i=0; i<49; i++){
        for(j=0; j<49; j++){
            div_id=String(i)+","+String(j);
            res="road_"+div_id;
            visit[i][j]=1;
            level[i][j]=0;
            pre_x[i][j]=-1;
            pre_y[i][j]=-1;

           

            visit_road[i][j]=0;
            val=document.getElementById(res).value;
            if(val==1){
                c++;
                visit[i][j]=0;
            }
        }
      }
    }

    function dfs(x,y,x1,y1,tx,ty,lev){
        
        if(x<0 || y<0 || x>49 || y>49)return;
        if(visit[x][y]==1 && level[x][y]<=lev)return;
        visit[x][y]=1;
        pre_x[x][y]=x1;
        pre_y[x][y]=y1;

        level[x][y]=lev;
        c1++;
        if(x==tx && y==ty)return;
        dfs(x+dx[0],y+dy[0],x,y,tx,ty,lev+1);
        dfs(x+dx[2],y+dy[2],x,y,tx,ty,lev+1);
        dfs(x+dx[3],y+dy[3],x,y,tx,ty,lev+1);
        dfs(x+dx[1],y+dy[1],x,y,tx,ty,lev+1);
    }

    function find_path(x,y,tx,ty){
           if(x==tx && y==ty)return 1;
           x1=pre_x[x][y];
           y1=pre_y[x][y];
          return 1+find_path(x1,y1,tx,ty);
    }

    function set_path(x,y,tx,ty){
           visit_road[x][y]=1;

           x1=pre_x[x][y];
           y1=pre_y[x][y];
           post_x[x1][y1]=x;
           post_y[x1][y1]=y;
           console.log(x,y);
           if(x==tx && y==ty)return;
          set_path(x1,y1,tx,ty);
    }


    function set_graph_path(x,y,tx,ty){
      visit_road[x][y]=1;
      console.log(x,y);
           if(x==tx && y==ty)return;
           console.log(x,y);
           x1=pre_x[x][y];
           y1=pre_y[x][y];
          
           div_id=String(x1)+","+String(y1);
           res="road_"+div_id;
           document.getElementById(div_id).className='visit';

           setTimeout(function(){
               set_graph_path(x1,y1,tx,ty);
            }, 40);
    }

    function reset_path(){
        for(i=0; i<49; i++){
          for(j=0; j<49; j++){
              div_id=String(i)+","+String(j);
              res="road_"+div_id;
              if(visit_road[i][j]==1)
               document.getElementById(div_id).className='visit_previous';
          }      
        }
    }

