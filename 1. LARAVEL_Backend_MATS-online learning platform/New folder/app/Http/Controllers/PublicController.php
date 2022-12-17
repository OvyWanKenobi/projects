<?php

namespace App\Http\Controllers;


use Illuminate\Http\Request;
use App\Models\Instructor;
use App\Models\Category;
use App\Models\Users;


class PublicController extends Controller
{
    public function login(){
        return view('Public.Login');
    }
    
    public function loginsubmit(Request $req){
        $this->validate($req,
            [
                'username'=>'required',
                'userpass'=>'required'
            ],
            [
                'username.required'=>'Please enter username',
                'userpass.required'=>'Please enter password',
            ]
            );

            
            
            $users = Users::all();
            
        
            foreach ($users as $u)
            if(($u->u_username == $req->username) && ($u->u_password == $req->userpass)){
                session(['username'=>$u->u_username]);
                session(['userid'=>$u->id]);
                return redirect()->route('instructor.home');
              // return view('Instructor.InstructorHome')->with('instructor',$instructor);
            }

            
            return "<h1>no user found</h1>";//
    }

    public function logout(){
        session()->flush();
        return redirect('/');
    }

    public function InstructorList(Request $req){
        $instructors = Instructor::all();
        $categories = Category::all();
        $catid="all";
        if(isset($req->catid)){$catid =decrypt($req->catid) ;}
        return view('Public.InstructorList')->with('instructors', $instructors)
                                            ->with('categories', $categories)
                                            ->with('catid',$catid);
    }

    public function InstructorDetails(Request $req){
        $instructor = Instructor::where('id','=',decrypt($req->id))->first();
        
        return view('Public.InstructorDetails')->with('instructor', $instructor);
    }

    public function ContactUs(){
        
       
        return view('Public.Contactus');
    }
}


