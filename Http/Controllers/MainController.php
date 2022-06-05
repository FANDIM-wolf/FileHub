<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\Document;
use App\Models\Vistitor;
use Illuminate\Support\Facades\DB;
use Illuminate\Support\Facades\Storage;
use Illuminate\Support\Facades\Cookie;
class MainController extends Controller
{
    
    public function show_main_page(){
        // collect tokens for checking and get user data
        // in positive case return user data and downloadable files 
        $visitors_from_db = Vistitor::all();
        $token_from_cookie = Cookie::get('token_for_archive_lmk');
        
        foreach ($visitors_from_db as $visitor){
            if($visitor->token == $token_from_cookie){
                if($visitor->type == "педагог"){
                    $documents = Document::orderBy('id','desc')->get();
                }
                else{
                    $documents = Document::orderBy('id','desc')->where('group_user' ,'=' ,$visitor->group_user)->get();
                }
                $user =$visitor;
                        
                return view('main' , ['documents'=> $documents ,'user'=> $user]);
            }
         
                
               
            
        }
        return redirect('/login');
    }

    public function upload_file(Request $request){
        //dd($request->group);
        
        //check for volunteer choice to set name 
        if ( strlen($request->file_name) > 0){
            $fileName = $request->file_name.'.'.$request->file->extension();
            $fileContent = $request->file->getContents();
            $document = new Document;
            $document->name_file = $fileName;
            $document->group_user = $request->group;
            $token_from_cookie = Cookie::get('token_for_archive_lmk');
        
      
            
            $document->save(); 
        }
        else{
            $fileName = $request->file->getClientOriginalName();
            $fileContent = $request->file->getContent();
            $document = new Document;
            $document->name_file = $fileName;
            $document->group_user = $request->group;
            $document->save(); 
        }
        
        Storage::disk('public')->put($fileName , $fileContent);
        
        return redirect('/');
    }

    public function upload_files(Request $request){
      
        $files = $request->file('files');
        foreach($files as $file){
            $fileName = $file->getClientOriginalName();
            $fileContent = $file->getContent();
            Storage::disk('public')->put($fileName , $fileContent);

            $document = new Document;
           
            $document->name_file = $fileName;
            $document->group_user =$request->group;
            $document->save();
        }
        
        return redirect('/');
    }
    public function get_upload_page(){
        $visitors_from_db = Vistitor::all();
        $token_from_cookie = Cookie::get('token_for_archive_lmk');
        foreach ($visitors_from_db as $visitor){
            if($visitor->token == $token_from_cookie){   
                $user =$visitor;  
                        
            }
        }
        return view("upload" , ['user' => $user]);
    }
    
    public function download_file(Request $request){
        // find file in db and download it
        //$file=Document::where('name_file','=',$request->name)->get();  
        //dd($file);
        return Storage::disk('public')->download($request->name);
    	
    }
    public function show_upload()
    {   
        $visitors_from_db = Vistitor::all();
        $token_from_cookie = Cookie::get('token_for_archive_lmk');
        
        foreach ($visitors_from_db as $visitor){
            if($visitor->token == $token_from_cookie){
                
                
                
                $user =$visitor;
                        
                return view('uploadbook' , ['user'=> $user]);
            }
         
                
               
            
        }
        
    }

     public function find_documents(Request $request)
    {   
        $visitors_from_db = Vistitor::all();
        $token_from_cookie = Cookie::get('token_for_archive_lmk');
        
        foreach ($visitors_from_db as $visitor){
            if($visitor->token == $token_from_cookie){
                $user = $visitor;
                $book_input = $request->search_input;
                $documents= Document::where('name_file','LIKE',"%{$book_input}%")->orderBy('created_at','desc')->get();
                return view('main' , ['documents'=>$documents ,'user'=>$user]);
            }
               
            
        }
    }

}
