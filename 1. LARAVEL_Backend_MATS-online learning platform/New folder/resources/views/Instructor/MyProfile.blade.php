@extends('layouts.instructorlayout')
@section('content')
<center>

    <h3>Profile Information</h3>
    <br>
    <div style="width:700px;  border:0px solid rgb(156, 155, 155); padding:15px 40px 15px 40px; background-color:rgb(240, 240, 240)">


@if (($instructor->ins_dp)==Null)
<img  src="{{asset('storage/nodpimage.png')}}"  style="width:175px; height:175px; object-fit:cover;"  alt="Image">
@else
<img  src="{{asset('storage/dp/instructors/'.$instructor->ins_dp)}}"  style="width:175px; height:175px; object-fit:cover; "  alt="Image">
@endif
<h4> Name: {{$instructor->ins_name}}</h4>
<h4> Degree: {{$instructor->ins_degree}}</h4> 
<h4> Bio: {{$instructor->ins_bio}}</h4> 
<h4> Category: {{$instructor->instructorcategory->cat_name}}</h4> 
<h4> Phone: {{$instructor->ins_phone}}</h4> 
<h4> Email: {{$instructor->ins_email}}</h4> 
<h4> Experience: {{$instructor->ins_exp}}</h4> 
<h4> Joining Date: {{date('F j, Y', strtotime($instructor->ins_joindate))}}</h4> 

<a class="btn btn-info" href="{{route('instructor.editprofile',['id'=>encrypt($instructor->id)])}}"> Edit Profile</a>
<a class="btn btn-primary" href=""> Change Password</a>
    </div>
</center>

@endsection