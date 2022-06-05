<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\Vistitor;
use Illuminate\Support\Facades\Cookie;
class LoginController extends Controller
{
    
    public function login_page(){
        return view('login');       
    }

    public function login(Request $request){
        // get all visitors and check for exist
        $visitors = Vistitor::all();
        foreach($visitors as $visitor){
            if($visitor->token == $request->token){
                //$name_for_cookie  = Cookie::forever('name',$user->name);
                //$password_for_cookie = Cookie::forever('password',$user->password); 
                
                $token_in_cookie_for_determine_of_user = Cookie::forever('token_for_archive_lmk',$visitor->token); 
                
                return redirect('/')->withCookie($token_in_cookie_for_determine_of_user);
                //return redirect("")
            }
        } 
        
        dd($visitors);
    }
}
