function [next_state, motor_cmd] = state_logic(state, wall_left, wall_front, wall_right, pos, heading, goal)
% FSM core logic: transitions + output control

% Define state constants
IDLE = 0; MOVE = 1; CHECK = 2; PLAN = 3;
TURN_L = 4; TURN_R = 5; TURN_B = 6; GOAL = 7;

% Default outputs
next_state = state;
motor_cmd = [0, 0]; % no movement

switch state
    case IDLE
        % Start when at initial position
        if all(pos == [0, 0])
            next_state = MOVE;
        end

    case MOVE
        % Continue moving until the next cell is reached
        if reached_next_cell(pos, heading)
            next_state = CHECK;
        else
            motor_cmd = [1, 1]; % basic forward PWM

    case CHECK
        % Update wall map and decide next action
        update_maze_map(pos, heading, wall_left, wall_front, wall_right);
        if all(pos == goal)
            next_state = GOAL;
        else
            next_state = PLAN;

    case PLAN
        % Decide turn angle: 0 = forward, ±90 = left/right, 180 = U-turn
        angle = plan_next_move(pos, heading, goal);
        if angle == 0
            next_state = MOVE;
        elseif angle == -90
            next_state = TURN_L;
        elseif angle == 90
            next_state = TURN_R;
        else
            next_state = TURN_B;

    case TURN_L
        if turned(heading, -90)
            next_state = MOVE;
        else
            motor_cmd = [-1, 1]; % turn left in place

    case TURN_R
        if turned(heading, 90)
            next_state = MOVE;
        else
            motor_cmd = [1, -1]; % turn right in place

    case TURN_B
        if turned(heading, 180)
            next_state = MOVE;
        else
            motor_cmd = [-1, -1]; % reverse turn

    case GOAL
        % Final state, stop all motion
        motor_cmd = [0, 0];
end
end
