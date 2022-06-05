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

    <form method="GET" action="/find_file" enctype="multipart/form-data">
    @csrf
     
            <input type="text" name="search_input"/>
    
        
       
        <button class="custom-file-upload" type="submit">Найти</button>
    
</form>

    <h2>Файлы доступные для скачивания:</h2>
    <br>
    
    @foreach($documents as $document)
    <div class="box_for_file">
    <a class="link" href="download/{{$document->name_file}}/from_hub">Файл:{{$document->name_file}}</a><br>
    <p class="data_time">Время загрузки:{{$document->created_at}}</p><br>
    <br>
  
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