@extends('layouts.instructorlayout')
@section('content')

<br>
<center>
    <div style="width:1000px;  border:0px solid rgb(156, 155, 155); text-align:left; padding:15px 40px 15px 40px; background-color:rgb(240, 240, 240)">
@if (($course->c_thumbnail)==Null)
<img  src="{{asset('storage/noimage.png')}}"  style="width:200px; height:200px; object-fit:cover;"  alt="Image">
@else
<img  src="{{asset('storage/coursethumbnail/'.$course->c_thumbnail)}}"  style="width:120px; height:120px; object-fit:cover;"  alt="Image">
@endif

<h3> Course: {{$course->c_title}}</h3>
<h4> Rating: 
    @php
    $rat=0;
    $totrat=count($course->studentsincourse);
    @endphp
    @foreach($course->ratingsofcourse as $cr)
    @php
        $rat=$rat + ($cr->r_rating)  ;
    @endphp
    
    @endforeach
    @if(count($course->ratingsofcourse) == 0)
    Not Rated
    @else
    {{$rat/$totrat}} /5  ({{$totrat}})</h4>
    @endif
    


   
    <h2 class="btn btn-outline-primary" style="font-size: 20;">Total Enrollments: {{count($course->studentsincourse)}}</h2>


</div>
<br>

<div style="width:1000px;  border:0px solid rgb(156, 155, 155); text-align:left; padding:15px 40px 15px 40px; background-color:rgb(240, 240, 240)">
<h3>Enrolled Students</h3>
<table class="table  table-hover">
    <tr>
        <th></th>
        <th>Name</th>
        <th>Username</th>
        <th>Topic Completed</th>
        <th>Topic Left</th>
        <th>Status</th>
  
    </tr>
  
    @foreach($course->studentsincourse as $st)
  
        <tr class="clickable  " style="cursor:pointer; "  onclick="window.location='{{route('instructor.studentdetails',['stid'=>encrypt($st->st_id)])}}'">
  
          <td >
              @if (($st->student->st_pro_pic)==Null)
              <img  src="{{asset('storage/nodpimage.png')}}"  style="width:100px; height:100px;"  alt="Image">
              @else
              <img  src="{{asset('storage/dp/student/'.$st->student->st_pro_pic)}}"  style="width:100px; height:100px; "  alt="Image">
              @endif
          </td>

          <td> {{$st->student->st_name}}</td>
            <td> {{$st->student->st_username}}</td>
            
            <td> {{$st->complete_topic}}</td>
            <td> {{($st->tot_topic)-($st->complete_topic)}}</td>
            
            <td>
              {{$st->sc_status}}
           </td>
           
    
        </tr>
    @endforeach
  </table>
</div>


@endsection