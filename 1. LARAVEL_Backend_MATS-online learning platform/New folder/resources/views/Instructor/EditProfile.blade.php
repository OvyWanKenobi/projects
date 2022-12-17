@extends('layouts.instructorlayout')
@section('content')
<center>
<br>
<h3>Edit Profile Information</h3>
<form class="form-floating " style="width:800px;  border:0px solid rgb(156, 155, 155); text-align:left; padding:40px 40px 40px 40px;  background-color:rgb(240, 240, 240)" action="{{route('instructor.editprofilesubmit')}}" method="post" enctype="multipart/form-data">
    {{@csrf_field()}}
    <div class="form-floating">
      
        <input type="text" class="form-control"  name="ins_name" value="{{ (old('ins_name')!==null) ? old('ins_name') : $instructor->ins_name }}" >
        <label for = "ins_name">Name :  </label> 
        @error('ins_name')
        <span>{{$message}}</span>
        @enderror
        <br>
    </div>
        <input type="hidden" name="ins_username" value="{{$instructor->ins_username}}" >
        <input type="hidden" name="ins_joindate" value="{{$instructor->ins_joindate}}" >
        <input type="hidden" name="ins_cat_fk" value="{{$instructor->ins_cat_fk}}" >
        <div class="form-floating">
        
         <input type="text"  class="form-control" name="ins_degree" value="{{ (old('ins_degree')!==null) ? old('ins_degree') : $instructor->ins_degree }}">
         <label for = "ins_degree"> Degree:  </label>
         @error('ins_degree')
        <span>{{$message}}</span>
        @enderror
        <br>
    </div>
        <div class="form-floating">
        
         <input type="text"  class="form-control" name="ins_bio" value="{{ (old('ins_bio')!==null) ? old('ins_bio') : $instructor->ins_bio }}" >
         <label for = "ins_bio"> Bio:  </label>
         @error('ins_bio')
        <span>{{$message}}</span>
        @enderror
        <br>
    </div>
        <div class="form-floating">
        
        <input type="tel"  class="form-control" name="ins_phone" value="{{ (old('ins_phone')!==null) ? old('ins_phone') : $instructor->ins_phone }}" >
        <label for = "ins_phone"> Phone:  </label>
        @error('ins_phone')
       <span>{{$message}}</span>
       @enderror
       <br>
    </div>
       <div class="form-floating">
      
       <input type="email"  class="form-control" name="ins_email" value="{{ (old('ins_email')!==null) ? old('ins_email') : $instructor->ins_email }}" >
       <label for = "ins_email"> Email:  </label>
       @error('ins_email')
      <span>{{$message}}</span>
      @enderror
      <br>
    </div>
      <div class="form-floating">
      
      <input type="text"  class="form-control" name="ins_exp" value="{{ (old('ins_exp')!==null) ? old('ins_exp') : $instructor->ins_exp }}" >
      <label for = "ins_exp"> Experience:  </label>
      @error('ins_exp')
     <span>{{$message}}</span>
     @enderror
     <br>
    </div>

     <div class="form-floating">
        <fieldset >
            <label style="float: left" for = "ins_dp">Profile Picture: </label>
         <input type="file"  class="form-control" name="ins_dp" value="{{ (old('ins_dp')!==null) ? old('ins_dp') : $instructor->ins_dp }}">
         
         @error('ins_dp') 
        <span>{{$message}}</span>
        @enderror 
        </fieldset>
        <br>
    </div>

        <input class="btn btn-success" type="submit" value="Update">
    </form>

</center>
@endsection