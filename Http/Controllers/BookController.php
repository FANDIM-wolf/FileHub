<?php

namespace App\Http\Controllers;

use App\Models\Book;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\DB;
use App\Models\Vistitor;
use Illuminate\Support\Facades\Storage;
use Illuminate\Support\Facades\Cookie;
class BookController extends Controller
{
    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {
        $visitors_from_db = Vistitor::all();
        $token_from_cookie = Cookie::get('token_for_archive_lmk');
        
        foreach ($visitors_from_db as $visitor){
            if($visitor->token == $token_from_cookie){
                $user = $visitor;
                $books = Book::orderBy("id","desc")->get();
               
                return view('books' , ['books'=> $books ,'user'=>$user ]);
            }
         
                
               
            
        }
       
    }

    /**
     * Show the form for creating a new resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function create(Request $request)
    {
        // //check for volunteer choice to set name 
        if ( strlen($request->file_name) > 0){
            $fileName = $request->file_name.'.'.$request->file->extension();
            $fileContent = $request->file->getContents();
            $document = new Book;
            $document->name_file = $fileName;
            dd($document->name_file);
            $document->image = $request->image;
            $document->save(); 
        }
        else{
            $fileName = $request->file->getClientOriginalName();
            $fileContent = $request->file->getContent();
            $document = new Book;
            $document->name = $request->name;
            //$filename = time().rand(1,324135). '.'.$request->image->getClientOriginalExtension();
            $document->image = $fileName;
            $document->name_file = $fileName;
            dd($document->name_file);
            $document->description = $request->description;
            $imageName = time().'.'.$request->image->extension(); 
            $request->image->move('img', $imageName);
            $document->image = $imageName;   
            $document->save(); 
        }
        
        Storage::disk('public')->put($fileName , $fileContent);
        
        return redirect('/');
    }

    /**
     * Store a newly created resource in storage.
     *
     * @param  \Illuminate\Http\Request  $request
     * @return \Illuminate\Http\Response
     */
    public function store(Request $request)
    {
        //
    }

    /**
     * Display the specified resource.
     *
     * @param  \App\Models\Book  $book
     * @return \Illuminate\Http\Response
     */
    public function show_upload(Request $request)
    {   //dd("nidsa");
        
    }

    /**
     * Show the form for editing the specified resource.
     *
     * @param  \App\Models\Book  $book
     * @return \Illuminate\Http\Response
     */
    public function edit(Book $book)
    {
        //
    }

    /**
     * Update the specified resource in storage.
     *
     * @param  \Illuminate\Http\Request  $request
     * @param  \App\Models\Book  $book
     * @return \Illuminate\Http\Response
     */
    public function update(Request $request, Book $book)
    {
        //
    }

    /**
     * Remove the specified resource from storage.
     *
     * @param  \App\Models\Book  $book
     * @return \Illuminate\Http\Response
     */
    public function destroy(Book $book)
    {
        //
       
    }
    public function show_search_book_page(){
        $books= Null;
        return view('book_search' , ['books'=>$books]);
    }
    /**
     * Find the specified resource from storage.
     *
     * @param  \App\Models\Book  $book
     * @return \Illuminate\Http\Response
     */
    public function find_books(Request $request)
    {   
        $visitors_from_db = Vistitor::all();
        $token_from_cookie = Cookie::get('token_for_archive_lmk');
        
        foreach ($visitors_from_db as $visitor){
            if($visitor->token == $token_from_cookie){
                $user = $visitor;
                $book_input = $request->search_input;
                $books= Book::where('name','LIKE',"%{$book_input}%")->orderBy('created_at','desc')->get();
                return view('book_search' , ['books'=>$books ,'user'=>$user]);
            }
               
            
        }
    }
}
