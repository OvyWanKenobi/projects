@extends('layouts.instructorlayout')
@section('content')
  
    
         @if (($student->st_pro_pic)==Null)
        <img id="dpicon" src="{{asset('storage/nodpimage.png')}}"  style="width:150px; height:150px;"  alt="Image">
        @else
        <img id="dpicon" src="{{asset('storage/dp/student/'.$student->st_pro_pic)}}"  style="width:150px; height:150px; "  alt="Image">
        @endif
    <h4> Name: {{$student->st_name}}</h4>
    <h4> Username: {{$student->st_username}}</h4> 
    <h4> Phone: {{$student->st_phone}}</h4> 
    <h4> Email: {{$student->st_email}}</h4> 
    <h4> Address: {{$student->st_address}}</h4> 

    <a class="btn btn-primary" href="#">Message Student</a>

     <h4>Your Courses the Student has taken: </h4> 

     @if(count($student->coursesinstudent)>0)
     
     <ul>
        @foreach($student->coursesinstudent as $c)
      
        @if(($c->course->instructorofcourse->ins_username) ==  Session::get('username'))
        <li>
          <h5> {{$c->course->c_title}} </h5>
        </li>
        @endif
        @endforeach
     </ul>
    
      @else
    <h5><span class="label label-warning" >No data found</span></h5>
    @endif
@endsection