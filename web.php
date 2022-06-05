<?php

use Illuminate\Support\Facades\Route;

use App\Http\Conttrollers;
/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| contains the "web" middleware group. Now create something great!
|
*/

Route::get('/','MainController@show_main_page')->name('main');
Route::get('/find_file','MainController@find_documents');
//routes for upload or upload multiple files 
Route::get('/upload','MainController@get_upload_page')->name('upload');
Route::post('/upload','MainController@upload_file')->name('upload');
Route::post('/upload_files','MainController@upload_files');
//routes for sign in 
Route::post('/login','LoginController@login')->name('login');
Route::get('/login','LoginController@login_page')->name('login');
//route(s) for download  certain file 
Route::get('/download/{name}/from_hub','MainController@download_file')->name('download');
Route::get('/uploadbook' ,'MainController@show_upload')->name('uploadbook');
//books
Route::get('/books' ,'BookController@index')->name('books');
Route::get('/book_search','BookController@show_search_book_page');
Route::get('/find_book','BookController@find_books');
Route::post('/uploadbook' ,'BookController@create')->name('uploadbook');
