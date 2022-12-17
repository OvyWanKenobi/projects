@extends('layouts.instructorlayout')
@section('content')
<center>

    
<h3>Add quiz</h3>

<form style="width:800px; border:0px solid rgb(180, 180, 180); text-align:left; padding:30px 30px 30px 75px; background-color:rgb(240, 240, 240)" action="{{route('instructor.addquizsubmit')}}" method="post">
    {{@csrf_field()}}


        <label for = "q_quesnumber">Question No.  </label> 
        <input type="text" style="border:0px;" name="q_quesnumber" value="{{$lastnumber+1}}" readonly >
        <br><br>
        
        <textarea name="q_ques" placeholder="Enter your question" rows="2" cols="30">{{old('q_ques')}}</textarea>
        @error('q_ques')
        <span>{{$message}}</span>
        @enderror
        <br><br>

        <input class="form-check-input" type="radio" name="q_ans" value="option1">
        A. <input type="text" name="q_option1" value="{{old('q_option1')}}" placeholder="Enter Option 1">
        @error('q_option1')
        <span>{{$message}}</span>
        @enderror
        <br><br>

        <input class="form-check-input" type="radio" name="q_ans" value="option2">
        B. <input type="text" name="q_option2" value="{{old('q_option2')}}" placeholder="Enter Option 2">
        @error('q_option2')
        <span>{{$message}}</span>
        @enderror
        <br><br>

        <input class="form-check-input" type="radio" name="q_ans" value="option3">
        C. <input type="text" name="q_option3" value="{{old('q_option3')}}" placeholder="Enter Option 3">
        @error('q_option3')
        <span>{{$message}}</span>
        @enderror
        <br><br>

        <input class="form-check-input" type="radio" name="q_ans" value="option4">
        D. <input type="text" name="q_option4" value="{{old('q_option4')}}" placeholder="Enter Option 4">
        @error('q_option4')
        <span>{{$message}}</span>
        @enderror
        <br><br>


        <input class="btn btn-primary" type="submit" value="Add">
    </form>

</center>
@endsection