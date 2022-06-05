<!Doctype html>
<html>
    <head>
        <title>LMK ARCHIVE</title>
        <link rel="preconnect" href="https://fonts.googleapis.com">
<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
<link href="https://fonts.googleapis.com/css2?family=Lato&display=swap" rel="stylesheet">
<link href="css/style.css" rel="stylesheet" >
<link href="js/script.js" rel="stylesheet" >

    </head>
<body>

 <header>
        <div class="inner">
            <div class="logo">
                <div>
                
                    <h3 id="click_menu">
                      ЛМК АРХИВ
                  </h3>
                    
                </div>
            </div>

            <nav>
                
            <li><span><a href="/">Файлы для скачивания</a></span></li>
                @if($user->type == "педагог")
                <li><span><a href="/upload">Загрузить файлы</a></span></li>
                @endif
               
                
                
            </nav>
        </div>
    </header>
    <div class="menu" id="menu">
    <h3><a id="link" href="/">Документы</a></h3>
        <h3><a id="link" href="/find_book">Книги</a></span></h3>
        @if($user->type == "педагог")
        <h3><a id="link" href="/upload">Загрузить файлы</a></span></h3>
        <h3><a id="link" href="/uploadbook">Загрузить Книгу</a></span></h3>
        @endif
        <h3><a id="link" href="/login">Войти</a></span></h3>
    </div>
    <div id="main">   
    <br>

    <br>
    
<form method="GET" action="/find_book" enctype="multipart/form-data">
    @csrf
     
            <input type="text" name="search_input"/>
    
        
       
        <button class="custom-file-upload" type="submit">Найти</button>
    
</form>
 
    @foreach($books as $book)
    <div>
    <div class="box_for_book">    
    <img src="img/{{$book->image}}" width="300">
    </div>
    <div class="box_for_book">   
    <a class="link" href="download/{{$book->name_file}}/from_hub">Файл:{{$book->name}}</a><br>
    <br>
    <h2>{{$book->name}}</h2>
    <br>
    <p class="description_of_book">{{$book->description}}</p>
    </div>
    </div>
    <br>
    @endforeach

    
    </div>

  

    <script text="javascript">
    
 
     //alert("Hello");
     var div_menu = document.getElementById("menu");
     var click_button = document.getElementById("click_menu"); 
     console.log(div_menu);
 console.log(click_button);
    
    
 
 // display div or close it .
          
         click_button.onclick= function(){
             
            div_menu.classList.toggle("open");
         }
       
 </script>

</body>
</html>