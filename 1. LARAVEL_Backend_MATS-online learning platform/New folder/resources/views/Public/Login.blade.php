@extends('Layouts.publiclayout')
@section('content')
  
      <h3>Login</h3>
         
    <form action="{{route('Loginsubmit')}}" method="post">
        {{@csrf_field()}}
        
            username: <input type="text" name="username" value="{{old('username')}}" placeholder="Username">
            @error('userid')
            <span>{{$message}}</span>
            @enderror
            <br>
            Password: <input type="password" name="userpass"  placeholder="Password"><br>
            @error('userpass')
            <span>{{$message}}</span>
            @enderror
            
            <input type="submit" value="Login" class ="btn btn-dark"><br>
        
        </form>
    
  
     
      
 @endsection