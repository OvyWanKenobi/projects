@extends('layouts.instructorlayout')
@section('content')
<center>
<div style="width:1000px;  border:0px solid rgb(180, 180, 180); text-align:left; padding:0px 40px 15px 40px; background-color:rgb(240, 240, 240)">
        <br>
        <h2 style="text-align:center;" >Course Title: {{$topic->topicofcourse->c_title}}</h2>

        <h4>Topic Number: {{$topic->t_number}}</h4>
        <h4>Topic Title: {{$topic->t_title}}</h4>



        @if ($topic->t_video)
        <h4>Video Lecture :</h4>
        <center>
            <video width="600" height="450" controls>
                <source src="{{URL::asset("/storage/lecturevideo/$topic->t_video")}}" type="video/mp4">
            Your browser does not support the video tag.
            </video>
        </center>
        @endif
        <br>

        @if(($topic->t_material)!==Null)
        <h4>Material : {{$topic->t_material}}</h4>
        @endif

        <a style="text-align:center;" class="btn btn-primary" href="{{route('instructor.edittopic',['topicid'=>encrypt($topic->id)])}}">Edit Topic</a> 

</div>
<br><br>
<div style="width:1000px;  border:0px solid rgb(180, 180, 180); text-align:left; padding:15px 40px 15px 40px; background-color:rgb(240, 240, 240)">
        
    <h2 style="text-align:center;"> Quiz </h2>
        

        @foreach($topic->quizintopic as $q)
            Ques#{{$q->q_quesnumber}}  {{$q->q_ques}} <br>
            <input class="form-check-input" type="radio" @if(($q->q_ans)==($q->q_option1))checked  @endif disabled> a. {{($q->q_option1)}} <br>
            <input class="form-check-input" type="radio" @if(($q->q_ans)==($q->q_option2))checked  @endif disabled> b. {{($q->q_option2)}} <br>
            <input class="form-check-input" type="radio" @if(($q->q_ans)==($q->q_option3))checked  @endif disabled> c. {{($q->q_option3)}} <br>
            <input class="form-check-input" type="radio" @if(($q->q_ans)==($q->q_option4))checked  @endif disabled> d. {{($q->q_option4)}} <br>
            <br>
        
        @endforeach

        <a class="btn btn-primary" href="{{route('instructor.addquiz',['topicid'=>encrypt($topic->id)])}}">Add question</a>

        </div>

</center>
        @endsection