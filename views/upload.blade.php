<!Doctype html>
<html>
    <head>
        <title>LMK ARCHIVE</title>
        <link rel="preconnect" href="https://fonts.googleapis.com">
<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
<link href="https://fonts.googleapis.com/css2?family=Lato&display=swap" rel="stylesheet">
<link href="css/style.css" rel="stylesheet" >
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

<main> 
<center>

@if( $user->type == "педагог")
<form method="POST" action="/upload" enctype="multipart/form-data">
    @csrf
        <br>
            <label class="custom-file-upload">
            <input type="file" name="file"/>
            Выбрать один документ
            </label>
        
        <br>
        
       
        <select name="group" >
        <option value="КСК 18-1">КСК 18-1</option>
        <option value="КСК 18-2">КСК 18-2</option>
        <option value="КСК 18-3">КСК 18-3</option>
        <option value="ИСиП 18-1">ИСиП 18-1</option>
        <option value="ИСиП 18-2">ИСиП 18-2</option>
        <option value="ИСиП 18-3">ИСиП 18-3</option>
        </select>
        <br>
        <button class="custom-file-upload" type="submit">Загрузить</button>
    
</form>

<form action="/upload_files" method="post" enctype="multipart/form-data">
{{ csrf_field() }}
<div class="form-group">
<label for="Product Name">Несколько файлов:</label>
<br />
<label class="custom-file-upload">
<input type="file" class="form-control" name="files[]" multiple />
Выбрать один или несколько документов
</label>
<br /><br />

<select name="group" >
    <option value="КСК 18-1">КСК 18-1</option>
    <option value="КСК 18-2">КСК 18-2</option>
    <option value="КСК 18-3">КСК 18-3</option>
    <option value="ИСиП 18-1">ИСиП 18-1</option>
    <option value="ИСиП 18-2">ИСиП 18-2</option>
    <option value="ИСиП 18-3">ИСиП 18-3</option>
</select>

<input type="submit" class="custom-file-upload"  value="Загрузить" />
</form>
@endif
@if($user->type == "студент")
 <h2>Извините , но студент не может загружать файлы на сервер.</h2>
 <img src="img/pepe.gif" width=450 height=350/>
@endif
</center>
</main>


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