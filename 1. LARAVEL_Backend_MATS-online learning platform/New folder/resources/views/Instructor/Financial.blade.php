@extends('layouts.instructorlayout')
@section('content')
<center>
<h2>Financial</h2>

@php
    $totearn = 0; 
@endphp

@foreach($instructor->coursesbyinstructor as $c)
    @php
    $totearn = $totearn + (($c->c_price)*(count($c->studentsincourse)))
    @endphp
@endforeach

<h4>Current Earning : {{$totearn}} BDT</h4>
<div style="width: 900px; margin-top:20px  " >
@if(count($instructor->coursesbyinstructor)>0)
<table class="table  table-hover" >
    <tr>
        <th>Image </th>
  
        <th>Course Title</th>
        <th>Course Price</th>
        <th>Enrollments count</th>
        <th>Earning</th>
  
    </tr>
  
    @foreach($instructor->coursesbyinstructor as $c)
        @if(($c->c_status=="Active") && (count($c->studentsincourse)>0))
        <tr class="clickable  " style="cursor:pointer; "  onclick="window.location='{{route('instructor.viewcourse',['id'=>encrypt($c->id)])}}'">
  
          <td >
              @if (($c->c_thumbnail)==Null)
              <img  src="{{asset('storage/noimage.png')}}"  style="width:100px; height:100px;"  alt="Image">
              @else
              <img  src="{{asset('storage/coursethumbnail/'.$c->c_thumbnail)}}"  style="width:100px; height:100px; "  alt="Image">
              @endif
          </td>
  
            <td> {{$c->c_title}}</td>
            <td> {{$c->c_price}}</td>
            <td>
              {{count($c->studentsincourse)}}
           </td>
           <td> 
               {{($c->c_price)*(count($c->studentsincourse))}}
           </td>
        </tr>
        @endif
    @endforeach
  </table>
  
  @else
  <h5><span class="label label-warning" >No data found</span></h5>
  @endif
</div>
  <center>
@endsection